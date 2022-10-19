#ifndef WORDCHECKSUM_H
#define WORDCHECKSUM_H

#include "wordwriter.h"

class WordChecksum
        : public WordAny
{
    const int _from,_to;
    std::vector<uchar> * _blob;
public:
    WordChecksum( std::vector<uchar> * blob ,
                  int p,
                  int f,
                  int t )
        :WordAny("CHK",&(*blob)[p]),_from(f),_to(t),_blob(blob){}
    void writeBytes();
    void parseBytes();

private:
    int getChecksum( )const;

};


#endif // WORDCHECKSUM_H
