#ifndef BYTEMANAGER_H
#define BYTEMANAGER_H

#include <qglobal.h>

//classe dont la responsabilité est d'ecrire et de lire un entier depuis la reference d'un octet
//utilisé par un WW pour ecrire ou lire 1 valeur
class ByteManager
{
    uchar * _octet;
    int _bitness;
    int _offset;
public:
    ByteManager(){}
    ByteManager( uchar * octet , int b, int o);
    uchar extractValue();
    void insertValue(uchar value);

    friend class WordWriter;
};


#endif // BYTEMANAGER_H
