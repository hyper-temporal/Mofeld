#ifndef SYNTHENUMELEMENT_H
#define SYNTHENUMELEMENT_H
#include "QString"
#include <stdexcept>
#include <QVariant>


class SynthEnumElement
{
public:
    SynthEnumElement(QString s, int i);
    const QString LaChaine;
    const int Lentier;
private:
};



#endif // SYNTHENUMELEMENT_H
