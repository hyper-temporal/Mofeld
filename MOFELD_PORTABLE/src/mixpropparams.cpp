#include "mixpropparams.h"


MixPropParams::MixPropParams()
{
    _meth_flex = Meth_flexibility::meth_Replace;
    _modify_Props= true ;
    _modify_Stuff= true ;
    _modify_Contr= true ;
    _modify_Val= true ;
}


QDataStream & operator << (QDataStream & out, const MixPropParams & Valeur)
{
    out << (int)Valeur._meth_flex
        << Valeur._modify_Props
        << Valeur._modify_Stuff
        << Valeur._modify_Contr
        << Valeur._modify_Val
           ;
    return out;
}

QDataStream & operator >> (QDataStream & in, MixPropParams & Valeur)
{

    int e1;
    in  >> e1
        >> Valeur._modify_Props
        >> Valeur._modify_Stuff
        >> Valeur._modify_Contr
        >> Valeur._modify_Val
           ;
    Valeur._meth_flex = (Meth_flexibility)e1;
    return in;
}
