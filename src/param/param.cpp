#include "param.h"

#include "param/paramcolor.h"
#include "param/paramclone.h"
#include "param/paramcostume.h"
#include "param/paramdelim.h"
#include "param/paramdestination.h"
#include "param/paramdirection.h"
#include "param/paramdock.h"
#include "param/parameffect.h"
#include "param/paraminteraction.h"
#include "param/paramjoinwords.h"
#include "param/paramkey.h"
#include "param/paramlistid.h"
#include "param/paramlistselec.h"
#include "param/parammath.h"
#include "param/parammessage.h"
#include "param/paramnumber.h"
#include "param/paramsound.h"
#include "param/paramstopchoices.h"
#include "param/paramstring.h"
#include "param/paramtouch.h"
#include "param/paramtype.h"
#include "param/paramvariables.h"

ParamBase* ParamBase::createParam(const QString &str,
                                  QWidget *parent,
                                  class Sprite *sprite,
                                  class DraggableElement *elem,
                                  QColor color)
{
    if(str.contains(QLatin1String("%dir")))
        return new ParamDirection(parent);
    if(str.contains(QLatin1String("%dst")))
        return new ParamDestination(parent);
    if(str.contains(QLatin1String("%key")))
        return new ParamKey(parent);
    if(str.contains(QLatin1String("%interaction")))
        return new ParamInteraction(parent);
    if(str.contains(QLatin1String("%msg")))
        return new ParamMessage(parent);
    if(str.contains(QLatin1String("%stopChoices")))
        return new ParamStopChoices(parent);
    if(str.contains(QLatin1String("%cln")))
        return new ParamClone(parent);
    if(str.contains(QLatin1String("%cst")))
        return new ParamCostume(parent, sprite);
    if(str.contains(QLatin1String("%eff")))
        return new ParamEffect(parent);
    if(str.contains(QLatin1String("%col")))
        return new ParamTouch(parent);
    if(str.contains(QLatin1String("%clr")))
        return new ParamColor(parent);
    if(str.contains(QLatin1String("%snd")))
        return new ParamSound(parent);
    if(str.contains(QLatin1String("%fun")))
        return new ParamMath(parent);
    if(str.contains(QLatin1String("%words")))
        return new ParamJoinWords(parent);
    if(str.contains(QLatin1String("%typ")))
        return new ParamType(parent);
    if(str.contains(QLatin1String("%delim")))
        return new ParamDelim(parent);
    if(str.contains(QLatin1String("%var")))
        return new ParamVariables(parent);
    if(str.contains(QLatin1String("%idx")))
        return new ParamListId(parent);
    if(str.contains(QLatin1String("%n")))
        return new ParamNumber(parent);
    if(str.contains(QLatin1String("%s")))
        return new ParamString(parent);
    if(str.contains(QLatin1String("%l")))
        return new ParamListSelec(parent);
    if(str.contains(QLatin1String("%b")))
        return new ParamDock(color, sprite, elem, parent);
    return 0;
}
