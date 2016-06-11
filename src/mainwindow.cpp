#include <QDialog>
#include <QFileDialog>
#include <QFont>
#include <QFontMetrics>
#include <QListWidgetItem>
#include <QPainterPath>
#include <QRadioButton>
#include <QDebug>
#include <QXmlStreamReader>

#include <Qsci/qscilexerpython.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "costume/costume.h"
#include "dragelem/dragelemcategory.h"
#include "dragelem/commandde.h"
#include "dragelem/hatde.h"
#include "dragelem/wrapperde.h"
#include "dragelem/predicatede.h"
#include "dragelem/reporterde.h"
#include "param/param.h"
#include "teacher/student.h"
#include "teacher/teacher.h"
#include "sprite.h"
#include "newspritename.h"
#include "saveloadclass.h"
#include "teacherlogin.h"

MainWindow* sMainWindow = 0;

const SpriteVector* MainWindow::getSpriteVector()
{
    return ui->spriteSelect->getSpriteVector();
}

void MainWindow::addSprite(Sprite *sprite)
{
    return ui->spriteSelect->addSprite(sprite);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _fileMenu(this),
    _editMenu(this),
    _audioEngine(this),
    _tmpDir("python") // TODO: make configurable (use AppDataLocation by default)
{
    sMainWindow = this;

    _pyController.addSysPath(QDir("python").absolutePath().toLatin1().data());

    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    ui->scene->setPyController(&_pyController);

    connect(this, SIGNAL(currentSpriteChanged(Sprite*)), &_audioEngine, SLOT(setCurrentSprite(Sprite*)));

    Sprite* sprite = new Sprite("sprite", this);
    Costume* costume = new Costume(sprite);
    costume->open("Assets/Costumes/dog2-a.png");
    costume->hide();
    sprite->setCurrentCostume(costume);

    ui->spriteSelect->addSprite(sprite);
    _currentSprite = sprite;
    emit changeCurrentSprite(sprite);

    _backgroundSprite = new Sprite(this);
    costume = new Costume(_backgroundSprite);
    costume->open("Assets/Backgrounds/desert.gif");
    costume->hide();
    _backgroundSprite->setCurrentCostume(costume);
    ((QHBoxLayout*) ui->selectionBackground->layout())->insertWidget(0, _backgroundSprite);

    InitializeDragElem(":/blocks.xml");

    connect(this, SIGNAL(newSound()), ui->soundSelect, SLOT(updateSoundList()));
    connect(this, SIGNAL(newCostume()), ui->costumeSelect, SLOT(updateCostumeList()));

    QFont font;
    font.setFamily("Consolas");
    font.setFixedPitch(true);
    font.setPointSize(10);
    QFontMetrics fm = QFontMetrics(font);
    ui->codeEditor->setFont(font);
    ui->codeEditor->setMarginsFont(font);
    ui->codeEditor->setMarginWidth(0, fm.width( "00000" ) + 5);
    ui->codeEditor->setMarginLineNumbers(0, true);
    ui->codeEditor->setFolding(QsciScintilla::BoxedTreeFoldStyle);
    ui->codeEditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    ui->codeEditor->setCaretLineVisible(true);
    ui->codeEditor->setCaretLineBackgroundColor(QColor("#ffe4e4"));
    ui->codeEditor->setMarginsBackgroundColor(QColor("#333333"));
    ui->codeEditor->setMarginsForegroundColor(QColor("#CCCCCC"));
    ui->codeEditor->setFoldMarginColors(QColor("#99CC66"), QColor("#333300"));

    QsciLexerPython lexer;
    lexer.setDefaultFont(font);
    ui->codeEditor->setLexer(&lexer);

    _fileMenu.addAction(tr("New"));
    _fileMenu.addAction(tr("Open"), this, SLOT(loadFromFile()));
    _fileMenu.addAction(tr("Save"), this, SLOT(saveToFile()));
    QMenu *exportMenu = _fileMenu.addMenu(tr("Export"));
    _fileMenu.addAction(tr("Reset"));

    exportMenu->addAction(tr("Python"), this, SLOT(exportAsPython()));

    _editMenu.addAction(tr("Undelete"));
    _editMenu.addAction(tr("Small stage layout"));
    _editMenu.addAction(tr("Turbo mode"));

    _loading = false;

    connect(this, SIGNAL(currentTeacherChanged(Teacher*)), ui->studentList, SLOT(currentTeacherChanged(Teacher*)));
}

void MainWindow::InitializeDragElem(const QString& path)
{
    QFile styleSheet(path);
    styleSheet.open(QFile::ReadOnly);
    QString xml = QLatin1String(styleSheet.readAll());

    QXmlStreamReader xmlReader(xml);
    QXmlStreamAttributes attributes;

    DraggableElement* lastElement;

    _LoadableElems.clear();

    uint paramIndex = 0;
    while(!xmlReader.atEnd())
    {
        if(xmlReader.readNext() == QXmlStreamReader::StartElement)
        {
            QString type = xmlReader.name().toString();
            if(type == QLatin1String("dragableelement"))
            {
                paramIndex = 0;
                attributes = xmlReader.attributes();
                DragElemCategory* category = GetCategoryByName(attributes.value(QLatin1String("category")).toString());
                QString type = attributes.value(QLatin1String("type")).toString();
                QString name = attributes.value(QLatin1String("name")).toString();
                QString spec = attributes.value(QLatin1String("spec")).toString();
                QColor color = category->getColor();

                if(!_Cgen.supported(name))
                    color = QColor();

                if(type == QLatin1String("command"))
                    lastElement = new CommandDE(name, spec, color, 0, this);
                else if(type == QLatin1String("hat"))
                    lastElement = new HatDE(name, spec, color, 0, this);
                else if(type == QLatin1String("wrapper"))
                    lastElement = new WrapperDE(name, spec, color, 0, this);
                else if(type == QLatin1String("predicate"))
                    lastElement = new PredicateDE(name, spec, color, 0, this);
                else if(type == QLatin1String("reporter"))
                    lastElement = new ReporterDE(name, spec, color, 0, this);

                lastElement->makeStatic();
                category->getElemList()->push_back(lastElement);
                _LoadableElems.push_back(lastElement);
            }
            else if(type == QLatin1String("parameter"))
            {
                attributes = xmlReader.attributes();
                QString def = attributes.value(QLatin1String("default")).toString();
                const std::vector<ParamBase*> *vec = lastElement->getParamsVector();
                while(paramIndex < vec->size() && !vec->at(paramIndex)->setValue(def))
                    paramIndex++;
                paramIndex++;
            }
            else if(type == QLatin1String("dragelemcategory"))
            {
                attributes = xmlReader.attributes();
                QString name = attributes.value(QLatin1String("name")).toString();
                QColor color = QColor(attributes.value(QLatin1String("color")).toString());
                DragElemCategory* category = new DragElemCategory(ui->elementList, name, color, this);
                ui->categorySelect->getCategoryList()->push_back(category);
            }
        }
    }
    ui->categorySelect->show();
}

QRect MainWindow::getScriptAreaRect()
{
    return QRect(ui->scriptArea->mapToGlobal(QPoint(0,0)), QSize(ui->scriptArea->width(), ui->scriptArea->height()));
}

void MainWindow::reloadCodeAll()
{
    if(_loading)
        return;
    // TODO
    if(_currentSprite)
        ui->codeEditor->setText(_Cgen.generateSprite(_currentSprite));

    QString name = "sprite_" + getBackgroundSprite()->getName();
    QString code = _Cgen.generateSprite(getBackgroundSprite(), true);
    _pyController.loadEntity(name.toLatin1().data(), getBackgroundSprite()->getName().toLatin1().data(), code.toLatin1().data());

    for (SpriteVector::const_iterator it = getSpriteVector()->begin(); it != getSpriteVector()->end(); it++)
    {
        QString name = "sprite_" + (*it)->getName();
        QString code = _Cgen.generateSprite(*it);
        _pyController.loadEntity(name.toLatin1().data(), (*it)->getName().toLatin1().data(), code.toLatin1().data());
    }
}

void MainWindow::reloadCodeSprite(Sprite *sprite)
{
    if(_loading)
        return;
    // TODO
    if(_currentSprite == sprite)
        ui->codeEditor->setText(_Cgen.generateSprite(_currentSprite));

    QString name = "sprite_" + sprite->getName();
    QString code = _Cgen.generateSprite(sprite);
    _pyController.loadEntity(name.toLatin1().data(), sprite->getName().toLatin1().data(), code.toLatin1().data());
}

DragElemCategory* MainWindow::GetCategoryByName(const QString& name)
{
    CategoryList *list = ui->categorySelect->getCategoryList();
    for(CategoryList::const_iterator category = list->begin(); category != list->end(); category++)
    {
        if((*category)->getName() == name)
            return *category;
    }
    return 0;
}

MainWindow::~MainWindow()
{
    // TODO: this is not nice!
    for(SpriteVector::const_iterator it = getSpriteVector()->begin(); it != getSpriteVector()->end(); it++)
        (*it)->OverrideParents();
    delete ui;
}

void MainWindow::loadFromFile()
{
    SaveLoadClass slc;
    _loading = true;
    // TODO
    ui->scriptArea->setCurrentSprite(0);
    if(slc.loadScratch(QStringLiteral("project.json"), ui->spriteSelect))
    {
        _currentSprite = getSpriteVector()->at(0);
        emit changeCurrentSprite(_currentSprite);
    }

    _loading = false;
    reloadCodeAll();
}

void MainWindow::saveToFile()
{
    SaveLoadClass slc;
    slc.saveScratch(QStringLiteral("project.json"), ui->spriteSelect);
}

void MainWindow::exportAsPython()
{
    _Cgen.generateAllFiles(_tmpDir, getBackgroundSprite(), getSpriteVector());
}

void MainWindow::on_soundFromFile_clicked()
{
    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open WAV file"), dir, "*.wav");
    if (fileNames.count())
    {
        _audioEngine.loadFile(fileNames.front());
        emit newSound();
    }
}

void MainWindow::on_costumeFromFile_clicked()
{
    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open PNG file"), dir, "*.png");
    if (fileNames.count())
    {
        Costume* costume = new Costume(_currentSprite);
        costume->open(fileNames.front());
        _currentSprite->addCostume(costume);
        emit newCostume();
        reloadCodeSprite(_currentSprite);
    }
}

void MainWindow::on_buttonFile_clicked()
{
    _fileMenu.popup(ui->buttonFile->pos()+QPoint(0, 23));
}

void MainWindow::on_buttonEdit_clicked()
{
    _editMenu.popup(ui->buttonEdit->pos()+QPoint(0, 23));
}

void MainWindow::on_buttonScriptStart_clicked()
{
    // TODO: remove reload
    reloadCodeAll();
    _pyController.sendStart();
}

void MainWindow::on_buttonScriptStop_clicked()
{
    _pyController.sendStop();
}

DraggableElement* MainWindow::createNewElement(QString ident, Sprite *sprite)
{
    // check all Elements
    for(std::vector<DraggableElement*>::const_iterator it = _LoadableElems.begin(); it != _LoadableElems.end(); it++)
    {
        if ((*it)->getIdentifier() == ident)
        {
            //qDebug() << ident;
            return (*it)->getCurrentElement(sprite, this);
        }
    }
    return 0;
}

void MainWindow::on_buttonAddDragElem_clicked()
{
    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open XML file"), dir, "*.xml");
    if (fileNames.count())
    {
        QFile addElem(fileNames.first());
        addElem.open(QFile::ReadOnly);
        QString xml = QLatin1String(addElem.readAll());

        QXmlStreamReader xmlReader(xml);
        QXmlStreamAttributes attributes;

        while(!xmlReader.atEnd())
        {
            if(xmlReader.readNext() == QXmlStreamReader::StartElement)
            {
                QString type = xmlReader.name().toString();
                if(type == QLatin1String("dragableelement"))
                {
                    attributes = xmlReader.attributes();
                    _currentStudent->addAddDragElem(attributes.value(QLatin1String("name")).toString());
                }
            }
        }
        setCurrentStudent(true);
    }
}

void MainWindow::on_spriteFromFile_clicked()
{
    NewSpriteName dialog;
    dialog.exec();

    QString name = dialog.getName();

    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open PNG file"), dir, "*.png");
    if (fileNames.count())
    {
        Sprite* sprite = new Sprite(name, this);
        ui->spriteSelect->addSprite(sprite);

        Costume* costume = new Costume(sprite);
        costume->open(fileNames.front());
        sprite->setCurrentCostume(costume);

        changeCurrentSprite(sprite);
        reloadCodeSprite(sprite);
    }
}

void MainWindow::on_logInTeacher_clicked()
{
    TeacherLogIn dialog;
    dialog.exec();

    _currentTeacher = new Teacher("Max Mustermann", "Musterschule");
    Student* student = new Student("Max Mustermann");
    _currentTeacher->addStudent(student);
    student = new Student("Maximillian Mustermann");
    _currentTeacher->addStudent(student);
    student = new Student("Maximus Mustermann");
    _currentTeacher->addStudent(student);

    emit currentTeacherChanged(_currentTeacher);

    int currentOnline = 0;
    for(uint i = 0; i < _currentTeacher->getStudentVector()->size(); i++)
    {
        if(_currentTeacher->getStudentVector()->at(i)->isOnline()) ++currentOnline;
    }

    ui->teacherName->setText(tr("Logged in as: %1").arg(_currentTeacher->getName()));
    ui->groupName->setText(tr("Course: %1").arg(_currentTeacher->getGroupName()));
    ui->currentLoggedIn->setText(tr("%1 of %2 students online").arg(
                                     QString::number(currentOnline), QString::number(_currentTeacher->getStudentVector()->size())));
}

void MainWindow::on_scriptArea_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalPos = ui->scriptArea->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction(tr("clean up"));
    myMenu.addAction(tr("add comment"));

    myMenu.exec(globalPos);
}

void MainWindow::on_listAddDragElem_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalPos = ui->listAddDragElem->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction(tr("delete"), this, SLOT(eraseItemAddDragElem()));

    myMenu.exec(globalPos);
}

void MainWindow::changeCurrentSprite(Sprite *sprite)
{
    _currentSprite = sprite;
    setCurrentCostume(sprite->getCostumeVector()->at(0));
    ui->codeEditor->setText(_Cgen.generateSprite(sprite));
    emit currentSpriteChanged(sprite);
}


void MainWindow::eraseItemAddDragElem()
{
    qDeleteAll(ui->listAddDragElem->selectedItems());
}

void MainWindow::setCurrentCostume(Costume *costume)
{
    ui->costumeLabel->setPixmap(QPixmap::fromImage(costume->getImage()->scaled(400, 400)));
}

void MainWindow::setCurrentStudent(bool)
{
    int studentNumber;
    for(studentNumber = 0; studentNumber < ui->studentList->_gridLayout.rowCount(); studentNumber++)
    {
        int index = studentNumber * 4;
        if(((QRadioButton*) ui->studentList->_gridLayout.itemAt(index)->widget())->isChecked()) break;
    }
    Student* student = _currentTeacher->getStudentVector()->at(studentNumber-1);
    ui->listAddDragElem->clear();
    for(uint i = 0; i < student->getAddDragElemVector()->size(); i++)
    {
        ui->listAddDragElem->insertItem(ui->listAddDragElem->count(),
            new QListWidgetItem(student->getAddDragElemVector()->at(i), ui->listAddDragElem));
    }
    _currentStudent = student;
    emit currentStudentChanged(student);
}

void MainWindow::dragElemContextMenuRequested(const QPoint &pos, DraggableElement *elem)
{
    if(!elem->isStatic())
    {
        QPoint globalPos = elem->mapToGlobal(pos);

        QMenu myMenu;
        myMenu.addAction(tr("duplicate"));
        myMenu.addAction(tr("delete"));
        myMenu.addAction(tr("add comment"));
        myMenu.addAction(tr("help"));

        myMenu.exec(globalPos);
    }
    else
    {
        QPoint globalPos = elem->mapToGlobal(pos);

        QMenu myMenu;
        myMenu.addAction(tr("help"));

        myMenu.exec(globalPos);
    }
}

void MainWindow::spriteContextMenuRequested(const QPoint &pos, Sprite *sprite)
{
    QPoint globalPos = sprite->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction(tr("info"));
    myMenu.addAction(tr("duplicate"));
    myMenu.addAction(tr("delete"));
    myMenu.addAction(tr("save to local file"));
    myMenu.addAction(tr("hide"));

    myMenu.exec(globalPos);
}

void MainWindow::on_scene_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalPos = ui->scene->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction(tr("save picture of stage"));

    myMenu.exec(globalPos);
}
