#include "synthenumelement.h"
#include "QString"


SynthEnumElement::SynthEnumElement(QString s, int i )
    :
      LaChaine(s),
      Lentier(i)
{

    if(!s.length()){
        throw std::logic_error("Lachaine ne peut pas être vide");

        return;
    }

}
