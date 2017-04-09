#include "Instrument.h"
#include "client/Models/operationModel.h"
using namespace OperationProps;

Instrument::Instrument()
{
    setName("°_°");
}

Instrument::Instrument(QString s, QVector<Parametre> lst)
    :_parametre(lst)
{
    try{
        setName(s);
    }catch(...){
        setName("'_'");
    }
}

Instrument::Instrument(const Instrument *other, int id, QString nom)
    :Entity(id,nom)
{
    foreach(Parametre  p, other->_parametre){
        Parametre *par = new Parametre(p);
        _parametre.append(*par);
    }
}



int Instrument::getValue(int idt)const{
    try {
        return _parametre[idt].getValue();
    } catch (...) {
        throw("parametre invalide");
    }
}

void Instrument::SetInstrument(const Instrument  i)
{
    replaceHeader(i);
    if(!_parametre.count()){
        replaceParametres(i);
    }
    else{
        updateParametres(i.getParametres(),new MixPropParams);
    }
}


void Instrument::replaceHeader(const Instrument i){
    _id = i._id;
    _name = i._name;
}

void Instrument::replaceParametres(const Instrument i){
    _parametre.clear();
    foreach(Parametre p ,i._parametre){
        _parametre.append(p);
    }
}

Parametre * Instrument::editParametre(int pid){
    if(pid < _parametre.count()){
        return &_parametre[pid];
    }else throw("erreur parametre inexistant");
}


void Instrument::updateParametre(const Parametre *p, bool contr,bool val){
    if(contr){
        setParamContrainte(p->getID(),p->getContrainte());
    }
    if(val){
        setParamValue(p->getID(),p->getValue());
    }
}

bool Instrument::paramBelongsToProp(int id){
    return getParametre(id)->_isProp;
}


void Instrument::updateParametre(const Parametre *p, const MixPropParams *mps)
{
    if(mps->_modify_Props && p->_isProp)
    {
        int id = p->getID();
        switch(mps->_meth_flex)
        {
            case meth_Force :
                updateParametre(p,mps->_modify_Contr,mps->_modify_Val);
                setPropriete(id,true);
                break;
            case meth_Replace :
                updateParametre(p,mps->_modify_Contr,mps->_modify_Val);
                setPropriete(id,true);
                break;
            case meth_Weak :
                if(!paramBelongsToProp(id)){
                    updateParametre(p,mps->_modify_Contr,mps->_modify_Val);
                    setPropriete(id,true);
                }
                break;
            default:
                break;
        };
    }
    else if(mps->_modify_Stuff && !p->_isProp)
    {
        updateParametre(p,mps->_modify_Contr,mps->_modify_Val);
    }
}



void Instrument::updateParametres(const QVector<Parametre> *pars, const MixPropParams * mps)
{
    foreach(Parametre  p , *pars)
    {
        updateParametre (&p,mps);
    }
}


void Instrument::setParamContrainte(int pid,const Contrainte * c){
    Parametre * p =  editParametre(pid);
    if(p!=NULL){
        p->setContrainte(c);
    }
}


void Instrument::setParamValue(int pid,int v){
    Parametre * p =  editParametre(pid);
    if(p!=NULL){
        p->setValue(v);
    }
}

void Instrument::regenerate(){

    foreach(Parametre param, _parametre){
        param.SetNewValue(param.getValue(),
                          param.getContrainte()->getMinValue(),
                          param.getContrainte()->getMaxValue()
                          );
    }
}

const Parametre * Instrument::getParametre(int pid)const
{
    if(pid < _parametre.count()){
        return &_parametre[pid];
    }else return NULL;
}

const Propriete *Instrument::getPropriete()const
{
    Propriete * prop = new  Propriete;
    for(int i(0);i<_parametre.count();i++){
        const Parametre *p = getParametre(i);
        if(p->_isProp){
            prop->addToPropriete(*p);
        }
    }
    return prop;
}

void Instrument::setPropriete(int id, bool isprop){
    editParametre(id)->_isProp = isprop;
}


QDataStream & operator << (QDataStream & out, const Instrument & Valeur)
{
    out << Valeur._id
        << Valeur._name
        << Valeur._datecreation
        << Valeur._parametre
           ;
    return out;
}
QDataStream & operator >> (QDataStream & in, Instrument & Valeur)
{
    in  >> Valeur._id
        >> Valeur._name
        >> Valeur._datecreation
        >> Valeur._parametre
           ;
    return in;
}


