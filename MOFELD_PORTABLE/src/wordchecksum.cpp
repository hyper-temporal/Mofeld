#include "wordchecksum.h"

#include <QDebug>
void WordChecksum::writeBytes(){
    _valueMgr ->setValue(getChecksum());
    WordWriter::writeBytes();
}

void  WordChecksum::parseBytes(){
    WordWriter::parseBytes();
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
