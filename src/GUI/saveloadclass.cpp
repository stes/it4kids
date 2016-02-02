#include "saveloadclass.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

SaveLoadClass::SaveLoadClass()
{

}


int SaveLoadClass::loadScratch(QString path){

    QFile loadFile(path);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return 1;
    }
    QByteArray saveData = loadFile.readAll();

    QJsonDocument JDoc(QJsonDocument::fromJson(saveData));

    if (JDoc.isArray())
    {
         qWarning("an array");
        return 1;
    }

    if (!JDoc.isObject())
    {
         qWarning("invalide file format");
        return 1;
    }

    //get amin object
    QJsonObject Jmain = JDoc.object();
        //tempoBPM scripts
    QJsonValue Jv = Jmain["tempoBPM"].toString();

    QString s = Jv.toString();

    qDebug() << s << Jv.toInt();

    return 0;
}
