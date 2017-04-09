#ifndef PROPERTIESMIXIPARAMS_H
#define PROPERTIESMIXIPARAMS_H

#include  "defs.h"

class MixPropParams
{
public:
        OperationProps::Meth_flexibility
                                _meth_flex;
        bool _modify_Props;
        bool _modify_Stuff;
        bool _modify_Contr;
        bool _modify_Val;
    MixPropParams();

private:
    friend QDataStream & operator << (QDataStream &, const MixPropParams &);
    friend QDataStream & operator >> (QDataStream &, MixPropParams &);
};
Q_DECLARE_METATYPE(MixPropParams)
QDataStream & operator << (QDataStream & out, const MixPropParams & Valeur);
QDataStream & operator >> (QDataStream & in, MixPropParams & Valeur);

#endif // PROPERTIESMIXIPARAMS_H
