#include "messagewriter.h"
#include "wordwriter.h"
#include "replacer.h"


WordWriter *Consequence::doIt(MessageWriter * mw){
    return mw->mutateWord(_position,_mot);
}

int WReplacer::getValue()const{
    return _WordPos->getValue();
}
