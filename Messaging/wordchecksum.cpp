#include "wordchecksum.h"

void WordChecksum::writeBytes(){
    _valueMgr ->setValue(getChecksum());
    WordWriter::writeBytes();
}

void  WordChecksum::parseBytes(){
    WordWriter::parseBytes();
    if (_valueMgr->getValue() != getChecksum()) throw("La checkSum est invalide");
}

int WordChecksum::getChecksum()const
{
    if( _from <= _to )
    {
        unsigned int checkS = 0;
        for( int i= _from; i <= _to;i++){
            checkS += (*_blob)[i];
        }
        checkS &= 0x7f;
        return(int)checkS;
    }
    else{
        return(int)0x7f;
    }
}
