#ifndef TARGETPROVIDER_H
#define TARGETPROVIDER_H

#include <vector>
#include <tuple>
#include "blofeldreplica.h"




//serve as a proxy
class TargetProvider
{
    BlofeldReplica* _target;
    MIOMgr _midiM;
    std::vector<std::pair<QString,int>> _bids;
    std::vector<std::pair<QString,int>> _bods;
    std::vector<BlofeldReplica> _synths;
public:
    TargetProvider(IBlofeldView * view)
        :_target(nullptr){
        _synths.clear();
        _bids = _midiM.getPortsIn("Blofeld");
        _bods = _midiM.getPortsOut("Blofeld");
        if(_bids.size() != _bods.size())
            throw "bad MIO";
        for(int i=0; i< _bids.size(); ++i ){
            auto min = _midiM.getinput(std::get<1>(_bids[i]));
            auto mout = _midiM.getoutput(std::get<1>(_bods[i]));
            _synths.push_back(
                        BlofeldReplica(
                            view,
                            min,
                            mout,
                            0));    //impossible to acces (blofelds pots are crap) and 0 by default so,

        }

        if(_synths.empty()){
            _synths.push_back(
                        BlofeldReplica(
                            view,
                            _midiM.getMockIn(),
                            _midiM.getMockOut(),
                            0));
        }
        setTarget(0);
    }
    BlofeldReplica* getTarget(){return _target;}
    void setTarget( int tid){ _target = &_synths[tid];}
    std::vector<std::pair<QString,int>>& getBids(){ return _bids; }
};

class IBlofeldView
{

public :
    virtual void updateView(const Arrangement * a)=0;
    virtual void updateView(const Instrument * i)=0;
    virtual void updateView(const Parametre * p)=0;
    virtual void updateView(int pid)=0;
    virtual void updateView(const Propriete * p)=0;

};

#endif // TARGETPROVIDER_H
