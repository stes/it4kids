#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);

    InitializeDragElem(":/blocks.xml");
    ui->categorySelect->setElemListWidget(ui->elementList);
    ui->categorySelect->setScriptAreaWidget(ui->scriptArea);
}

void MainWindow::InitializeDragElem(const QString& path)
{
    QFile styleSheet(path);
    styleSheet.open(QFile::ReadOnly);
    QString xml = QLatin1String(styleSheet.readAll());

    QXmlStreamReader xmlReader(xml);
    QXmlStreamAttributes attributes;

    int j = 0;
    int i = 0;
    while(!xmlReader.atEnd())
    {
        j++;
        qDebug() << "J" << j;
        if(xmlReader.readNext() == QXmlStreamReader::StartElement)
        {
            i++;
            qDebug() << "i" << i;
            QString type = xmlReader.name().toString();
            if(type == "dragableelement")
            {
                attributes = xmlReader.attributes();
                DragElemCategory* category = GetCategoryByName(attributes.value("category").toString());
                DragableElement* element = new DragableElement(attributes.value("spec").toString(), category->_color, ui->scriptArea);
                qDebug() << attributes.value("spec");
                category->_elemList.push_back(element);
            }
            else if(type == "dragelemcategory")
            {
                attributes = xmlReader.attributes();
                DragElemCategory* category = new DragElemCategory(attributes.value("name").toString(), QColor(attributes.value("color").toString()), this);
                ui->categorySelect->_categoryList.push_back(category);
            }
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
