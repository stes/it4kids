#include <QDialog>
#include <QFileDialog>
#include <QFont>
#include <QFontMetrics>
#include <QListWidgetItem>
#include <QPainterPath>
#include <QRadioButton>
#include <QDebug>
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

MainWindow* _sMainWindow = 0;

SpriteVector* MainWindow::getSpriteVector()
{
   return ui->spriteSelect->getSpriteVector();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _dateiMenu(this), _bearbeitenMenu(this), _audioEngine(this), _Cgen(this)
{
    _sMainWindow = this;

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

    _backgroundSprite = new Sprite("background", this);
    costume = new Costume(_backgroundSprite);
    costume->open("Assets/Backgrounds/desert.gif");
    costume->hide();
    _backgroundSprite->setCurrentCostume(costume);
    ((QHBoxLayout*) ui->selectionBackground->layout())->insertWidget(0, _backgroundSprite);

    InitializeDragElem(":/blocks.xml");

    //ui->categorySelect->setElemListWidget(ui->elementList);
    ui->categorySelect->setScriptAreaWidget(ui->scriptArea);

    ui->scriptArea->setMainWindow(this);

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

    _dateiMenu.addAction("Neu");
    _dateiMenu.addAction("Hochladen von deinem Computer");
    _dateiMenu.addAction("Herunterladen auf deinen Computer");
    _dateiMenu.addAction("Zurücksetzen");

    _bearbeitenMenu.addAction("Löschen rückgängig");
    _bearbeitenMenu.addAction("Kleine Bühnengröße");
    _bearbeitenMenu.addAction("Turbo-Modus");

    connect(this, SIGNAL(currentTeacherChanged(Teacher*)), ui->studentList, SLOT(currentTeacherChanged(Teacher*)));

    _Cgen.generateFiles();
}

void MainWindow::InitializeDragElem(const QString& path)
{
    _LoadableDrags.clear();
    QFile styleSheet(path);
    styleSheet.open(QFile::ReadOnly);
    QString xml = QLatin1String(styleSheet.readAll());

    QXmlStreamReader xmlReader(xml);
    QXmlStreamAttributes attributes;

    DragableElement* lastElement;

    uint paramIndex = 0;
    while(!xmlReader.atEnd())
    {
        if(xmlReader.readNext() == QXmlStreamReader::StartElement)
        {
            QString type = xmlReader.name().toString();
            if(type == "dragableelement")
            {
                paramIndex = 0;
                attributes = xmlReader.attributes();
                DragElemCategory* category = GetCategoryByName(attributes.value("category").toString());
                if(attributes.value("type").toString() == "command")
                {
                    lastElement = new CommandDE(attributes.value("name").toString(), attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "hat")
                {
                    lastElement = new HatDE(attributes.value("name").toString(), attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "wrapper")
                {
                    lastElement = new WrapperDE(attributes.value("name").toString(), attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "predicate")
                {
                    lastElement = new PredicateDE(attributes.value("name").toString(), attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "reporter")
                {
                    lastElement = new ReporterDE(attributes.value("name").toString(), attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                category->_elemList.push_back(lastElement);
            }
            else if(type == "parameter")
            {
                attributes = xmlReader.attributes();
                while(paramIndex < lastElement->_paramsVector.size() &&
                      !lastElement->_paramsVector[paramIndex]->setValue(
                          attributes.value("default").toString())) paramIndex++;
                paramIndex++;
            }
            else if(type == "dragelemcategory")
            {
                attributes = xmlReader.attributes();
                DragElemCategory* category = new DragElemCategory(ui->elementList, attributes.value("name").toString(), QColor(attributes.value("color").toString()), this);
                ui->categorySelect->_categoryList.push_back(category);
            }
            _LoadableDrags.push_back(lastElement);
        }

    }
    ui->categorySelect->show();
}

void  MainWindow::reloadCode()
{
    // TODO
    ui->codeEditor->setText(_Cgen.generateSprite(_currentSprite));

    _Cgen.generateFiles();
    _pyController.loadApp("main");
}

DragElemCategory* MainWindow::GetCategoryByName(const QString& name)
{
    for(CategoryList::iterator category = ui->categorySelect->_categoryList.begin(); category != ui->categorySelect->_categoryList.end(); category++)
    {
        if((*category)->_label.text() == name) return (*category);
    }
    return 0;
}

MainWindow::~MainWindow()
{
    delete ui;
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
        _currentSprite->getCostumeVector()->push_back(costume);
        emit newCostume();
    }
}

void MainWindow::on_buttonFile_clicked()
{
    _dateiMenu.popup(ui->buttonFile->pos()+QPoint(0, 23));
}

void MainWindow::on_buttonEdit_clicked()
{
    _bearbeitenMenu.popup(ui->buttonEdit->pos()+QPoint(0, 23));
}

void MainWindow::on_buttonScriptStart_clicked()
{
    //SaveLoadClass* slc = new SaveLoadClass(this);
    //slc->loadScratch("project.json");
    //slc->saveScratch();

    // TODO
    reloadCode();
    _pyController.sendStart();
}


DragableElement* MainWindow::createNewElement(QString)
{
   /* qDebug() << s;
    //check all Elements
    for(std::vector<DragableElement*>::iterator it = _LoadableDrags.begin(); it != _LoadableDrags.end(); ++it)
    {
        qDebug() << "he" << _LoadableDrags.size();
        qDebug() << (it == _LoadableDrags.end());
        qDebug() << ((*it) == 0);
        qDebug() << (*it)->getType();
        qDebug() << (*it)->getIdentifier();
        qDebug() << "ho";
        if ((*it)->getIdentifier() == s)
        {
            DragableElement* ele = (*it)->getCurrentElement(ui->scriptArea);
            return ele;
        }
    }
    */
    return (DragableElement*)0;
}

void MainWindow::on_buttonScriptStop_clicked()
{
    _pyController.sendStop();
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
                if(type == "dragableelement")
                {
                    attributes = xmlReader.attributes();
                    _currentStudent->addAddDragElem(attributes.value("name").toString());
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

        _Cgen.generateFiles();
        _pyController.loadApp("main");
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

    ui->teacherName->setText("Angemeldet als: " + _currentTeacher->getName());
    ui->groupName->setText("Kurs: " + _currentTeacher->getGroupName());
    ui->currentLoggedIn->setText(QString::number(currentOnline) + " von " + QString::number(_currentTeacher->getStudentVector()->size()) +
                                 " Schüler/innen online");
}

void MainWindow::on_scriptArea_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalPos = ui->scriptArea->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Aufräumen");
    myMenu.addAction("Kommentar hinzufügen");

    myMenu.exec(globalPos);
}

void MainWindow::on_listAddDragElem_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalPos = ui->listAddDragElem->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Löschen",  this, SLOT(eraseItemAddDragElem()));

    myMenu.exec(globalPos);
}

void MainWindow::changeCurrentSprite(Sprite *sprite)
{
    _currentSprite = sprite;
    setCurrentCostume(sprite->getCostumeVector()->at(0));
    ui->codeEditor->setText(_Cgen.generateSprite(sprite->getName()));
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

void MainWindow::dragElemContextMenuRequested(const QPoint &pos, DragableElement *elem)
{
    if(elem->isDragged())
    {
        QPoint globalPos = elem->mapToGlobal(pos);

        QMenu myMenu;
        myMenu.addAction("Duplizieren");
        myMenu.addAction("Löschen");
        myMenu.addAction("Kommentar hinzufügen");
        myMenu.addAction("Hilfe");

        myMenu.exec(globalPos);
    } else
    {
        QPoint globalPos = elem->mapToGlobal(pos);

        QMenu myMenu;
        myMenu.addAction("Hilfe");

        myMenu.exec(globalPos);
    }
}

void MainWindow::spriteContextMenuRequested(const QPoint &pos, Sprite *sprite)
{
    QPoint globalPos = sprite->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Info");
    myMenu.addAction("Duplizieren");
    myMenu.addAction("Löschen");
    myMenu.addAction("Als lokale Datei speichern");
    myMenu.addAction("verstecke dich");

    myMenu.exec(globalPos);
}

void MainWindow::on_scene_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalPos = ui->scene->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Bild der Bühne speichern");

    myMenu.exec(globalPos);
}