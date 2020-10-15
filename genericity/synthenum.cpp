#include "synthenum.h"

SynthEnum::SynthEnum()
{
    _nom="";
    //MesElements = *new QList<SynthEnumElement>();
}
SynthEnum::SynthEnum(QList<QString> elts){

    int i(0);

    foreach(QString str, elts){

        SynthEnumElement * se = new SynthEnumElement(str,i++);
        MesElements.append(se);
    }
}

SynthEnum::SynthEnum(QString s)
{
    if(!s.length()){
        throw std::logic_error("Lachaine ne peut pas être vide");
        return;
    }

    if(!s.trimmed().length()){
         throw std::logic_error("Lachaine ne peut pas être constrituée d'espaces purs");
        return;
    }

    _nom = s;

}



void SynthEnum::EnumValidation( SynthEnumElement * e){

    QString s = e->LaChaine.trimmed();
    int ini = e->Lentier;

    for(int i=0;i<MesElements.count();i++){

        SynthEnumElement * el = MesElements.at(i);

        QString scomp = el->LaChaine.trimmed();

        if(!QString::compare(scomp,s,Qt::CaseSensitive)){

        throw std::logic_error( "Exemple d'exception" );

        }
        if(ini == el->Lentier ){

        throw std::logic_error( "Exemple d'exception" );         }
    }

    MesElements.append(e);

}


int SynthEnum::getClosestValue(int input)const{
    int res = input;

    int ret= getElements().at(0)->Lentier;

    {
        for (int i(0);i< CountElements();i++){

            int num = getElement(i)->Lentier;
            int tempres = (int)std::abs((float)input-num);
            if(tempres<res)
            {
                res=tempres;
                ret=num;
            }
         }
    }
    return ret;

}

int SynthEnum::getNewValue(int input)const{
    return getNewValue(input,getMin(),getMax());
}
int SynthEnum::getNewValue(int input, int min, int max)const{
    int result(input);
    int range=  max-min;
    if(range>0 && range<128){
        result = min +(qrand()% (range+1));}
    return getClosestValue(result) ;
}
