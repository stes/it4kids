#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QFileDialog>
#include <QFont>
#include <QFontMetrics>
#include <QListWidgetItem>
#include <QPainterPath>
#include <QDebug>

#include "audioengine.h"
#include "costume.h"
#include "dragelemcategory.h"
#include "commandde.h"
#include "hatde.h"
#include "param.h"
#include "sprite.h"
#include "wrapperde.h"
#include "predicatede.h"
#include "reporterde.h"
#include "qscilexerpython.h"
#include "newspritename.h"
#include "saveloadclass.h"

MainWindow* _sMainWindow = 0;

SpriteVector* MainWindow::getSpriteVector()
{
   return ui->spriteSelect->getSpriteVector();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), _dateiMenu(this), _bearbeitenMenu(this)
{
    _sMainWindow = this;

    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    _audioEngine = new AudioEngine(this);
    connect(this, SIGNAL(currentSpriteChanged(Sprite*)), _audioEngine, SLOT(setCurrentSprite(Sprite*)));

    Sprite* sprite = new Sprite("sprite", this);
    Costume* costume = new Costume(sprite);
    costume->open(":/Assets/libraryOn.png");
    costume->hide();
    sprite->setCurrentCostume(costume);

    ui->spriteSelect->addSprite(sprite);
    _currentSprite = sprite;
    _backgroundSprite = new Sprite(this);
    ((QHBoxLayout*) ui->selectionBackground->layout())->insertWidget(0, _backgroundSprite);
    emit changeCurrentSprite(sprite);

    InitializeDragElem(":/blocks.xml");

    //ui->categorySelect->setElemListWidget(ui->elementList);
    ui->categorySelect->setScriptAreaWidget(ui->scriptArea);

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


    _Cgen= new CodeGenerator(this);

    _dateiMenu.addAction("Neu");
    _dateiMenu.addAction("Hochladen von deinem Computer");
    _dateiMenu.addAction("Herunterladen auf deinen Computer");
    _dateiMenu.addAction("Zurücksetzen");

    _bearbeitenMenu.addAction("Löschen rückgängig");
    _bearbeitenMenu.addAction("Kleine Bühnengröße");
    _bearbeitenMenu.addAction("Turbo-Modus");


    connect(ui->listAddDragElem, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customContextMenuRequestedAddDragElem(QPoint)));

}

void MainWindow::InitializeDragElem(const QString& path)
{
    _LoadableDrags = {};
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
            //Vector aller dragable Elements för loadinf file Purpuses
            _LoadableDrags.push_back(lastElement);
        }

    }
    ui->categorySelect->show();
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
        _audioEngine->loadFile(fileNames.front());
    }
    emit newSound();
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
    }
    emit newCostume();
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
    SaveLoadClass* slc = new SaveLoadClass(this);
    //slc->loadScratch("C:\\Users\\Karl\\Documents\\GitHub\\it4kids\\src\\project.json");
    //slc->saveScratch();

   _Cgen->generateFile();

    QFile file("python/out.py");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    ui->codeEditor->setText(in.readAll());
    file.close();
    ui->scene->loadApp("out");
    ui->scene->sendStart();
}


DragableElement* MainWindow::createNewElement(QString s)
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
    ui->scene->sendStop();
>>>>>>> GUI
}

void MainWindow::on_buttonAddDragElem_clicked()
{
    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open PNG file"), dir, "*.xml");
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
                    ui->listAddDragElem->insertItem(ui->listAddDragElem->count(),
                        new QListWidgetItem(attributes.value("name").toString(), ui->listAddDragElem));
                }
            }
        }
    }
}

void MainWindow::on_spriteFromFile_clicked()
{
    NewSpriteName dialog;
    dialog.exec();

    Sprite* sprite = new Sprite(dialog.getName(), this);
    ui->spriteSelect->addSprite(sprite);

    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open PNG file"), dir, "*.png");
    if (fileNames.count())
    {
        Costume* costume = new Costume(sprite);
        costume->open(fileNames.front());
        sprite->setCurrentCostume(costume);
    }

    changeCurrentSprite(sprite);
}

void MainWindow::changeCurrentSprite(Sprite *sprite)
{
    _currentSprite = sprite;
    setCurrentCostume(sprite->getCostumeVector()->at(0));
    emit currentSpriteChanged(sprite);
}

void MainWindow::customContextMenuRequestedAddDragElem(const QPoint &pos)
{
    QPoint globalPos = ui->listAddDragElem->mapToGlobal(pos);

    QMenu myMenu;
    myMenu.addAction("Löschen",  this, SLOT(eraseItemAddDragElem()));

    myMenu.exec(globalPos);
}

void MainWindow::eraseItemAddDragElem()
{
    qDeleteAll(ui->listAddDragElem->selectedItems());
}

void MainWindow::setCurrentCostume(Costume *costume)
{
    ui->costumeLabel->setPixmap(QPixmap::fromImage(costume->getImage()->scaled(400, 400)));
}
