#ifndef BYTEMANAGER_H
#define BYTEMANAGER_H

#include <qglobal.h>

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
