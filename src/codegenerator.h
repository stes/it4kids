#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <vector>

#include <QDir>
#include <QMap>
#include <QString>

class DraggableElement;
class Sprite;

typedef std::vector<Sprite*> SpriteVector;

class CodeGenerator
{
public:
    CodeGenerator();
    QString generateSprite(const Sprite *sprite, bool stage = false);
    QString generateMain(const Sprite *bgSprite, const SpriteVector *spriteVec);

    void generateAllFiles(const QDir &directory, const Sprite *bgSprite, const SpriteVector *spriteVec);
    void generateSpriteFile(const QDir &directory, const Sprite *sprite, bool stage = false);
    void generateMainFile(const QDir &directory, const Sprite *bgSprite, const SpriteVector *spriteVec);

    bool supported(const QString &ident);

private:
    struct Event
    {
        QStringList _code;
        QString _register;
    };

    void writeToFile(const QString &path, const QString &data);

    QString addQuotes(const QString &str);

    QString generateCode(const DraggableElement* element, int sub);
    QString generateParam(const class ParamBase* param);
    QString indent(int indent);
    QString indentCode(const QStringList *code, int indent = 0, const QString &content = QString());

    QStringList processCodeField(const QJsonArray &Code);
    void generateMap();

    int _indentCounter;
    QMap<QString, int> _eventCounters;

    QMap<QString, QStringList> _snippets;
    QMap<QString, Event> _events;
    QMap<QString, QStringList> _commands;
    QMap<QString, QStringList> _controls;
    QMap<QString, QString> _expressions;
};
#endif // CODEGENERATOR_H
