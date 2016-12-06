#include "param.h"

#include "paramcolor.h"
#include "paramcombobox.h"
#include "paramnumber.h"
#include "parampredicate.h"
#include "paramstring.h"

ParamBase* ParamBase::createParam(const QString &str,
                                  QWidget *parent,
                                  class Sprite *sprite,
                                  class DraggableElement *elem,
                                  QColor color)
{
    if(str.contains(QLatin1String("%clr")))
        return new ParamColor(parent);
    if(str.contains(QLatin1String("%n")))
        return new ParamNumber(sprite, elem, parent);
    if(str.contains(QLatin1String("%s")))
        return new ParamString(parent);
    if(str.contains(QLatin1String("%b")))
        return new ParamPredicate(color, sprite, elem, parent);
    if(str.contains(QLatin1String("%com")))
        return new ParamComboBox(parent);
    return 0;
}
