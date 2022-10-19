#include "frmfx.h"
#include "blofeldreplica.h"
#include "frmsynthctrl_rotary.h"
#include "frmsynthctrl_combobox.h"
#include "combotool.h"
int Mix,fxp1, fxp2,fxp3,fxp4,fxp5,fxp6,fxp7,fxp8, fxp9,fxp10,fxp11,fxp12,fxp13,fxp14,fxType;

frmFX::frmFX(const BlofeldReplica *synth,Instrument *instru,int fxNum, QString n, QWidget *parent)
    :ctrlSection(n, parent, QBoxLayout::LeftToRight )
{
    initFX(fxNum);

/*00*/    addCtrl(new frmSynthCtrl_combobox( parent ,synth, instru->editParametre(fxType)));
/*01*/    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(Mix)));

    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp1)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp2)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp3)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp4)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp5)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp6)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp7)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp8)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp9)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp10)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp11)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp12)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp13)));
    addCtrl(new frmSynthCtrl_rotary( parent ,synth, instru->editParametre(fxp14)));

    _leaves = getLeafs();

    setFX(fxNum,fxType);
}

void frmFX::hideAll(){

    _ctrls.at(1+1)->hide();
    _ctrls.at(1+2)->hide();
    _ctrls.at(1+3)->hide();
    _ctrls.at(1+4)->hide();
    _ctrls.at(1+5)->hide();
    _ctrls.at(1+6)->hide();
    _ctrls.at(1+7)->hide();
    _ctrls.at(1+8)->hide();
    _ctrls.at(1+9)->hide();
    _ctrls.at(1+10)->hide();
    _ctrls.at(1+11)->hide();
    _ctrls.at(1+12)->hide();
    _ctrls.at(1+13)->hide();
    _ctrls.at(1+14)->hide();
}


void frmFX::setFX( int fxNum, int fxType)
{

    initFX(fxNum);
    hideAll();

    switch(fxType)
    {
        case FXTYPE_Bypass:
            break;
        case FXTYPE_Chorus:
            setFX_Chorus();
            break;
        case FXTYPE_Flanger:{
            setFX_Flanger();
        }
            break;
        case FXTYPE_Phaser:{
            setFX_Phaser();
        }
            break;
        case FXTYPE_Overdrive:{
            setFX_Overdrive();
        }
            break;
        case FXTYPE_TripleFX:{
            setFX_TripleFX();
        }
            break;
        case FXTYPE_Delay:{
            if(fxNum!=1)return;
            setFX_Delay();
        }
            break;
        case FXTYPE_ClkDelay:{
            if(fxNum!=1)return;
            setFX_ClckDelay();
        }
            break;
        case FXTYPE_Reverb:{
            if(fxNum!=1)return;
            setFX_Reverb();
        }
            break;
        default:
            break;
    }
}


void frmFX::initFX(int fxNum){
     if(fxNum==0)
    {
        fxType=93;
        Mix=94;
        fxp1=95;
        fxp2=96;
        fxp3=97;
        fxp4=98;
        fxp5=99;
        fxp6=100;
        fxp7=101;
        fxp8=102;
        fxp9=103;
        fxp10=104;
        fxp11=105;
        fxp12=106;
        fxp13=107;
        fxp14=108;
    }
    else if(fxNum==1)
    {

        fxType=109;
        Mix=110;
        fxp1=111;
        fxp2=112;
        fxp3=113;
        fxp4=114;
        fxp5=115;
        fxp6=116;
        fxp7=117;
        fxp8=118;
        fxp9=119;
        fxp10=120;
        fxp11=121;
        fxp12=122;
        fxp13=123;
        fxp14=124;
    }
    else{
        throw("regarding fx .... well, bad number");
    }


}

void frmFX::leafModif(CtrlParamLeaf * leaf, QWidget * w, QString s)
{
    leaf->_controle = w;
    leafModif(leaf,s);
}

void frmFX::leafModif(CtrlParamLeaf * leaf, QString s)
{
    leaf->_lbTitre.setText(s);
    leaf->show();
}

void frmFX::setFX_Chorus( )
{
    leafModif(_leaves.at(1+1),"Speed");
    leafModif(_leaves.at(1+2),"Depth");
}
void frmFX::setFX_Flanger(){
    leafModif(_leaves.at(1+1),"Speed");
    leafModif(_leaves.at(1+2),"Depth");
    leafModif(_leaves.at(1+5),"Feedback");
    leafModif(_leaves.at(1+9),"Polarity");
}
void frmFX::setFX_Phaser(){
    leafModif(_leaves.at(1+1),"Speed");
    leafModif(_leaves.at(1+2),"Depth");
    leafModif(_leaves.at(1+5),"Feedback");
    leafModif(_leaves.at(1+6),"Center");
    leafModif(_leaves.at(1+7),"Spacing");
    leafModif(_leaves.at(1+9),"Polarity");

}
void frmFX::setFX_Overdrive(){
    leafModif(_leaves.at(1+1),"Drive");
    leafModif(_leaves.at(1+3),"Post Gain");
    leafModif(_leaves.at(1+6),"Cutoff");
    leafModif(_leaves.at(1+10),"Curve");
}
void frmFX::setFX_TripleFX(){
    leafModif(_leaves.at(1+1),"Speed");
    leafModif(_leaves.at(1+2),"Depth");
    leafModif(_leaves.at(1+4),"Chorus Mix");
    leafModif(_leaves.at(1+5),"Sample&Hold");
    leafModif(_leaves.at(1+6),"Overdrive");
}
void frmFX::setFX_Delay(){
    leafModif(_leaves.at(1+4),"Length");
    leafModif(_leaves.at(1+5),"Feedback");
    leafModif(_leaves.at(1+6),"Cutoff");
    leafModif(_leaves.at(1+9),"Polarity");
    leafModif(_leaves.at(1+10),"Spread");
}
void frmFX::setFX_ClckDelay(){

    leafModif(_leaves.at(1+5),"Feedback");
    leafModif(_leaves.at(1+6),"Cutoff");
    leafModif(_leaves.at(1+9),"Polarity");
    leafModif(_leaves.at(1+10),"Spread");
    leafModif(_leaves.at(1+11),"Length");
}
void frmFX::setFX_Reverb(){

    leafModif(_leaves.at(1+1),"Size");
    leafModif(_leaves.at(1+2),"Shape");
    leafModif(_leaves.at(1+3),"Decay");
    leafModif(_leaves.at(1+6),"LowPass");
    leafModif(_leaves.at(1+7),"HighPass");
    leafModif(_leaves.at(1+8),"Diffusion");
    leafModif(_leaves.at(1+9),"Damping");
}


