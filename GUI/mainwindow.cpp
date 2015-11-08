#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "reporterde.h"

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

    DragableElement* lastElement;

    while(!xmlReader.atEnd())
    {
        if(xmlReader.readNext() == QXmlStreamReader::StartElement)
        {
            QString type = xmlReader.name().toString();
            if(type == "dragableelement")
            {
                attributes = xmlReader.attributes();
                DragElemCategory* category = GetCategoryByName(attributes.value("category").toString());
                if(attributes.value("type").toString() == "command")
                {
                    lastElement = new CommandDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "hat")
                {
                    lastElement = new HatDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "wrapper")
                {
                    lastElement = new WrapperDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "predicate")
                {
                    lastElement = new PredicateDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                else if(attributes.value("type").toString() == "reporter")
                {
                    lastElement = new ReporterDE(attributes.value("spec").toString(), category->_color,attributes.value("type").toString(), ui->scriptArea, this);
                }
                category->_elemList.push_back(lastElement);
            }
            else if(type == "parameter")
            {
                attributes = xmlReader.attributes();
                lastElement->_defaultValues.push_back(attributes.value("default").toString());
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
    return 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
