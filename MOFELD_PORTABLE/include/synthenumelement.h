#ifndef SYNTHENUMELEMENT_H
#define SYNTHENUMELEMENT_H
#include "QString"
#include <stdexcept>
#include <QVariant>


class SynthEnumElement
{
public:
//    SynthEnumElement();
    SynthEnumElement(QString s, int i);
    const QString LaChaine;
    const int Lentier;
//    static void initSynthEnumElementSystem ();
private:

};

#endif // SYNTHENUMELEMENT_H
