#include "messagewriter.h"
#include "wordwriter.h"
#include "consequence.h"

//retourne le mot muté
WordWriter *Consequence::doIt(MessageWriter * mw){
    return mw->mutateWord(_position,_mot);
}

int WReplacer::getValue()const{
    return _WordPos->getValue();
}
