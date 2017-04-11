#include "bytemanager.h"

ByteManager::ByteManager(uchar *octet, int b, int o)
    :_octet(octet), _bitness(b), _offset(o)
{
    if(_bitness<=0) throw("le vecteur est de taille negative");
    if(_offset<0) throw("l'offset est de taille negative");
    if(_bitness> 8- _offset) throw("le mot ne peut etre contenu dans un seul octet");
}



uchar ByteManager::extractValue(){
    uchar init = *_octet;
    uchar mask0 = init<<(8-_bitness-_offset);
    uchar mask1 = mask0>>(8-_bitness);
    return mask1;
}

void ByteManager::insertValue(uchar value )
{
    if(value <= (0b1 << (_bitness))-1){

        int rLen = _offset;
        int lLen =  8-(_bitness+_offset);

        uchar lMask0 = 0xFF << lLen;
        uchar lMask = ~(lMask0 >> lLen);
        uchar rMask0 = 0xFF >> rLen;
        uchar rMask = ~(rMask0 << rLen);
        uchar fMask = lMask | rMask;

        uchar freg0 = *_octet ;
        uchar freg = freg0 & fMask;

        uchar fValLone0 = value;
        uchar fValLone1 = fValLone0 << rLen;
        uchar fValCert = fValLone1 & (~fMask);//ne devrai rien changer

        uchar fVal = fValCert | freg;

        *_octet  = fVal;
    }
    else throw("la valeur ne peut pas etre contenu");
}
