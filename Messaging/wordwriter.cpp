#include "wordwriter.h"

//single shared byte
WordWriter::WordWriter( ValueMgr * vm,  uchar *  octetRef,  int bitness , int offset )
    : _valueMgr(vm)
{
    ByteManager * bm = new ByteManager(octetRef, bitness, offset);
    _byteMgrs.append(*bm);
}

//single shared byte
WordWriter::WordWriter( WordWriter * w,  uchar *  octetRef)
    : _valueMgr(w->getValueMgr())
{
    int i(0);
    foreach(ByteManager  bm, w->_byteMgrs){
        ByteManager * nbm = new ByteManager(&octetRef[i], bm._bitness, bm._offset);
        _byteMgrs.append(*nbm);
        i++;
    }
}

void WordBig::setValue(int v){
    if(v<0){
        uchar c1 = (v&0x000FC000)>>14+ 0x40;
        _byteMgrs[0].insertValue(c1);
    }
    else
    {
        uchar c1 = (v&0x000FC000)>>14;
        _byteMgrs[0].insertValue(c1);
    }
    uchar c2 = (v&0x00003F80)>>7;
    _byteMgrs[1].insertValue(c2);

    uchar c3 = v&0x0000007F;
    _byteMgrs[1].insertValue(c3);

}


//multi byteWr instanciation, la bitness precisee en argument permet la decoupe de la valeur contenue par le Valuemgr
WordWriter::WordWriter( ValueMgr * vm,  uchar *  octetRef,  int bitness  )
    : _valueMgr(vm)
{
    int valueBitness = _valueMgr->getBitness();
    int length =  valueBitness/bitness ;
    int bitnessRemain = valueBitness % bitness;
    int start=0;
    if(bitnessRemain>0){
        ByteManager * bm = new ByteManager(&octetRef[0], bitnessRemain, 0);
        _byteMgrs.append(*bm);
        length+=1;
        start=1;
    }
    for(int i(start);i<length;i++){
        ByteManager * bm = new ByteManager(&octetRef[i], bitness, 0);
        _byteMgrs.append(*bm);
    }
}

WordEnum::WordEnum(QString s, uchar * oct, int enid)
    :WordWriter(new ValueEnum(s,enid),oct, 7)
{}

WordEnum::WordEnum(QString s, uchar  * oct ,int enid, int bitness, int offset)
    :WordWriter(new ValueEnum(s,enid),oct,bitness,offset)
{}
WordEnum::WordEnum(ValueMgr * vm,  uchar  * oct )
    :WordWriter(vm,oct,7,0)
{}

//constante
WordConstante::WordConstante(QString s,  uchar * oct ,int cst)
    :WordWriter(new ValueConstante(s,cst),oct,8,0)
{}

//any
WordAny::WordAny(QString s,  uchar * oct )
    :WordWriter(new ValueAny7b(s),oct,7 )
{}
//any
WordAny::WordAny(QString s,  uchar * oct, int v )
    :WordWriter(new ValueAny7b(s,v),oct,7 )
{}

WordRange::WordRange(QString s,  uchar * oct ,int min, int max)
    :WordWriter(new ValueRange(s,7,min,max),oct,7 )
{}



void  WordWriter::parseBytes(){
    int p(0);
    int res(0);
    foreach(ByteManager b, _byteMgrs){
        uchar c = b.extractValue();
        res  = (res << p * b._bitness) + c;
        p++;
    }
    _valueMgr->setValue(res);
}


void WordWriter::writeBytes(){

    int res = _valueMgr->getValue();
    foreach(ByteManager b, _byteMgrs)
    {
        int shifter = b._bitness;
        uchar extractorMask = ~((0xff>>shifter)<<shifter);
        uchar c = res & extractorMask;
        b.insertValue(c);
        res = (res >> shifter);
    }
}




