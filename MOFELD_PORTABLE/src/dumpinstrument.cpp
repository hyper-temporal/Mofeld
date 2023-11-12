#include "dumpinstrument.h"

DumpInstrument::DumpInstrument()
    :Blofable(392,0x10)
{
    setAdressContent();
    setDataContent();
    setChecksum();
}
void DumpInstrument::setAdressContent(){
    appenWord( new WordAny ( "BB",&_message[5],0));
    appenWord( new WordAny  ( "NN",&_message[6],0));
}
void DumpInstrument::setChecksum(){
    appenWord(new WordChecksum( &_message,390,7,389));
}

std::vector<uchar> * DumpInstrument::getMessage(int macid,int chid){
    setWordValue(5,0x7f);
    setWordValue(6,chid);
    return Blofable::getMessage(macid);
}

std::vector<uchar> * DumpInstrument::getMessage(int macid,int bank, int pgm){
    setWordValue(5,bank);
    setWordValue(6,pgm);
    return Blofable::getMessage(macid);
}

QVector<ParametreCom *> DumpInstrument::updateParam(std::vector<uchar> * v){

    int a1,a2;
    a1 = v->at(6);
    a2 = v->at(7);
    QVector<ParametreCom *> ps = getParams (a1,a2);
    foreach(ParametreCom * p, ps){
        p->parseMessage(v);
    }
    return ps;
}
ParametreCom DumpInstrument::createParam(int pid){
    return *_Parametres.at(pid);
}

ParametreCom * DumpInstrument::getParam(int pid){
    return _Parametres.at(pid);
}

ParametreCom * DumpInstrument::getParam(int a1,int a2){
    foreach(ParametreCom * wp, _Parametres){
        if(wp->adressMatch(a1,a2))
        return wp;
    }
    return NULL;
}

ParametreCom * DumpInstrument::getParam(std::vector<uchar> * v){
    int a1,a2;
    a1 = v->at(6);
    a2 = v->at(7);
    ParametreCom * p = getParam(a1,a2);
    if(p!=NULL){
        p->setParamChannel(v->at(5));
        p->setParamValue(v->at(8));
    }
    return p;
}

QVector<ParametreCom *> DumpInstrument::getParams(int a1,int a2){
    QVector<ParametreCom *> lst;
    foreach(ParametreCom * wp, _Parametres){
        if(wp->adressMatch(a1,a2))
        {
            lst.append(wp);
        }
    }
    return lst;
}

QVector<ParametreCom *> DumpInstrument::getParams(int pid){
    ParametreCom * p = getParam(pid);
    return getParams(p->_ad1,p->_ad2);
}

QVector<ParametreCom *> DumpInstrument::getParams(std::vector<uchar> * v){
    ParametreCom * p = getParam(v);
    return getParams(p->_ad1,p->_ad2);
}

void  DumpInstrument::setEmbeddedName(QString name){
    int offset=348;
    for(int i=0; i<16 && name.length()>i;i++)
    {
        char c ;
        if(i >= name.length()){
            c = (char)0x20;
        }
        else{
            c = name.at(i).toLatin1();
        }
        const char res(c);
        setWordValue(i+offset,res);
    }
}

QString DumpInstrument::getEmbeddedName(){

    QString s="";
    for(int i=348;i<364;i++)
    {
        s+= (char)getWordValue(i);
    }
    return s;
}

void DumpInstrument::addParametre(WordWriter * w,int ad1, int ad2)
{
    appenWord(w);
    ParametreCom * wp;
    wp = new ParametreCom(_Parametres.count(),
                                     ad1,ad2,w
                                     );
    _Parametres.append(wp);
}



static QVector<Consequence*> * fx1Off(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(102,new WordEnum ( "Effect 1 Parameter 1",&(*mess)[137], BLOT_BYPASS)));
    csfx2->append(new Consequence(103,new WordEnum ("Effect 1 Parameter 2",&(*mess)[138], BLOT_BYPASS)));
    csfx2->append(new Consequence(104,new WordEnum ("Effect 1 Parameter 3",&(*mess)[139], BLOT_BYPASS)));
    csfx2->append(new Consequence(105,new WordEnum ("Effect 1 Parameter 4",&(*mess)[140], BLOT_BYPASS)));
    csfx2->append(new Consequence(106,new WordEnum ("Effect 1 Parameter 5",&(*mess)[141], BLOT_BYPASS)));
    csfx2->append(new Consequence(107,new WordEnum ("Effect 1 Parameter 6",&(*mess)[142], BLOT_BYPASS)));
    csfx2->append(new Consequence(108,new WordEnum ("Effect 1 Parameter 7",&(*mess)[143], BLOT_BYPASS)));
    csfx2->append(new Consequence(109,new WordEnum ("Effect 1 Parameter 8",&(*mess)[144], BLOT_BYPASS)));
    csfx2->append(new Consequence(110,new WordEnum ("Effect 1 Parameter 9",&(*mess)[145], BLOT_BYPASS)));
    csfx2->append(new Consequence(111,new WordEnum ("Effect 1 Parameter 10",&(*mess)[146], BLOT_BYPASS)));
    csfx2->append(new Consequence(112,new WordEnum ("Effect 1 Parameter 11",&(*mess)[147], BLOT_BYPASS)));
    csfx2->append(new Consequence(113,new WordEnum ("Effect 1 Parameter 12",&(*mess)[148], BLOT_BYPASS)));
    csfx2->append(new Consequence(114,new WordEnum ("Effect 1 Parameter 13",&(*mess)[149], BLOT_BYPASS)));
    csfx2->append(new Consequence(115,new WordEnum ("Effect 1 Parameter 14",&(*mess)[150], BLOT_BYPASS)));
    return csfx2;
}
static QVector<Consequence*> * fx2Off(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(118,new WordEnum ("Effect 2 Parameter 1",&(*mess)[153], BLOT_BYPASS)));
    csfx2->append(new Consequence(119,new WordEnum ("Effect 2 Parameter 2",&(*mess)[154], BLOT_BYPASS)));
    csfx2->append(new Consequence(120,new WordEnum ("Effect 2 Parameter 3",&(*mess)[155], BLOT_BYPASS)));
    csfx2->append(new Consequence(121,new WordEnum ("Effect 2 Parameter 4",&(*mess)[156], BLOT_BYPASS)));
    csfx2->append(new Consequence(122,new WordEnum ("Effect 2 Parameter 5",&(*mess)[157], BLOT_BYPASS)));
    csfx2->append(new Consequence(123,new WordEnum ("Effect 2 Parameter 6",&(*mess)[158], BLOT_BYPASS)));
    csfx2->append(new Consequence(124,new WordEnum ("Effect 2 Parameter 7",&(*mess)[159], BLOT_BYPASS)));
    csfx2->append(new Consequence(125,new WordEnum ("Effect 2 Parameter 8",&(*mess)[160], BLOT_BYPASS)));
    csfx2->append(new Consequence(126,new WordEnum ("Effect 2 Parameter 9",&(*mess)[161], BLOT_BYPASS)));
    csfx2->append(new Consequence(127,new WordEnum ("Effect 2 Parameter 10",&(*mess)[162], BLOT_BYPASS)));
    csfx2->append(new Consequence(128,new WordEnum ("Effect 2 Parameter 11",&(*mess)[163], BLOT_BYPASS)));
    csfx2->append(new Consequence(129,new WordEnum ("Effect 2 Parameter 12",&(*mess)[164], BLOT_BYPASS)));
    csfx2->append(new Consequence(130,new WordEnum ("Effect 2 Parameter 13",&(*mess)[165], BLOT_BYPASS)));
    csfx2->append(new Consequence(131,new WordEnum ("Effect 2 Parameter 14",&(*mess)[166], BLOT_BYPASS)));
    return csfx2;
}
static QVector<Consequence*> * fx1Chorus(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(102,new WordEnum ("Speed",&(*mess)[137], BLOT_STANDARD)));
    csfx2->append(new Consequence(103,new WordEnum ("Depth",&(*mess)[138], BLOT_STANDARD)));
    return csfx2;
}
static QVector<Consequence*> * fx2Chorus(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(118,new WordEnum ("Speed",&(*mess)[153], BLOT_STANDARD)));
    csfx2->append(new Consequence(119,new WordEnum ("Depth",&(*mess)[154], BLOT_STANDARD)));
    return csfx2;
}
static QVector<Consequence*> * fx1Flanger(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(102,new WordEnum ("Speed",&(*mess)[137], BLOT_STANDARD)));
    csfx2->append(new Consequence(103,new WordEnum ("Depth",&(*mess)[138], BLOT_STANDARD)));
    csfx2->append(new Consequence(106,new WordEnum ("Feedback",&(*mess)[141], BLOT_STANDARD)));
    csfx2->append(new Consequence(107,new WordEnum ("Polarity",&(*mess)[142], BLOT_POLARITY)));
    return csfx2;
}
static QVector<Consequence*> * fx2Flanger(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(118,new WordEnum ("Speed",&(*mess)[153], BLOT_STANDARD)));
    csfx2->append(new Consequence(119,new WordEnum ("Depth",&(*mess)[154], BLOT_STANDARD)));
    csfx2->append(new Consequence(122,new WordEnum ("Feedback",&(*mess)[157], BLOT_STANDARD)));
    csfx2->append(new Consequence(123,new WordEnum ("Polarity",&(*mess)[158], BLOT_POLARITY)));
    return csfx2;
}
static QVector<Consequence*> * fx1Phaser(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(102,new WordEnum ("Speed",&(*mess)[137], BLOT_STANDARD)));
    csfx2->append(new Consequence(103,new WordEnum ("Depth",&(*mess)[138], BLOT_STANDARD)));
    csfx2->append(new Consequence(104,new WordEnum ("Feedback",&(*mess)[141], BLOT_STANDARD)));
    csfx2->append(new Consequence(105,new WordEnum ("Center",&(*mess)[142], BLOT_STANDARD)));
    csfx2->append(new Consequence(106,new WordEnum ("Spacing",&(*mess)[143], BLOT_STANDARD)));
    csfx2->append(new Consequence(107,new WordEnum ("polarity",&(*mess)[145], BLOT_POLARITY)));
    return csfx2;
}
static QVector<Consequence*> * fx2Phaser(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(118,new WordEnum ("Speed",&(*mess)[153], BLOT_STANDARD)));
    csfx2->append(new Consequence(119,new WordEnum ("Depth",&(*mess)[154], BLOT_STANDARD)));
    csfx2->append(new Consequence(122,new WordEnum ("Feedback",&(*mess)[157], BLOT_STANDARD)));
    csfx2->append(new Consequence(123,new WordEnum ("Center",&(*mess)[158], BLOT_STANDARD)));
    csfx2->append(new Consequence(124,new WordEnum ("Spacing",&(*mess)[159], BLOT_STANDARD)));
    csfx2->append(new Consequence(126,new WordEnum ("polarity",&(*mess)[161], BLOT_POLARITY)));
    return csfx2;

}
static QVector<Consequence*> * fx1Overdrive(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(103,new WordEnum ("Drive",&(*mess)[138], BLOT_STANDARD)));
    csfx2->append(new Consequence(104,new WordEnum ("Post gain",&(*mess)[139], BLOT_STANDARD)));
    csfx2->append(new Consequence(107,new WordEnum ("Cutoff",&(*mess)[142], BLOT_STANDARD)));
    csfx2->append(new Consequence(111,new WordEnum ("Curve",&(*mess)[146], BLOT_FX_DRIVESHAPE)));
    return csfx2;
}
static QVector<Consequence*> * fx2Overdrive(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(119,new WordEnum ("Drive",&(*mess)[154], BLOT_STANDARD)));
    csfx2->append(new Consequence(120,new WordEnum ("Post gain",&(*mess)[155], BLOT_STANDARD)));
    csfx2->append(new Consequence(123,new WordEnum ("Cutoff",&(*mess)[158], BLOT_STANDARD)));
    csfx2->append(new Consequence(127,new WordEnum ("Curve",&(*mess)[162], BLOT_FX_DRIVESHAPE)));
    return csfx2;
}
static QVector<Consequence*> * fx1TripleFX(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(102,new WordEnum ("Speed",&(*mess)[137], BLOT_STANDARD)));
    csfx2->append(new Consequence(103,new WordEnum ("Depth",&(*mess)[138], BLOT_STANDARD)));
    csfx2->append(new Consequence(105,new WordEnum ("Mix",&(*mess)[140], BLOT_STANDARD)));
    csfx2->append(new Consequence(106,new WordEnum ("S&H",&(*mess)[141], BLOT_STANDARD)));
    csfx2->append(new Consequence(107,new WordEnum ("Overdrive",&(*mess)[142], BLOT_STANDARD)));
    return csfx2;
}
static QVector<Consequence*> * fx2TripleFX(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(118,new WordEnum ("Speed",&(*mess)[153], BLOT_STANDARD)));
    csfx2->append(new Consequence(119,new WordEnum ("Depth",&(*mess)[154], BLOT_STANDARD)));
    csfx2->append(new Consequence(121,new WordEnum ("Mix",&(*mess)[156], BLOT_STANDARD)));
    csfx2->append(new Consequence(122,new WordEnum ("S&H",&(*mess)[157], BLOT_STANDARD)));
    csfx2->append(new Consequence(123,new WordEnum ("Overdrive",&(*mess)[158], BLOT_STANDARD)));
    return csfx2;
}
static QVector<Consequence*> * fx2Delay(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(121,new WordEnum ("Length",&(*mess)[156], BLOT_STANDARD)));
    csfx2->append(new Consequence(122,new WordEnum ("FeedBack",&(*mess)[157], BLOT_STANDARD)));
    csfx2->append(new Consequence(123,new WordEnum ("Cutoff",&(*mess)[158], BLOT_STANDARD)));
    csfx2->append(new Consequence(126,new WordEnum ("Polarity",&(*mess)[161], BLOT_POLARITY)));
    csfx2->append(new Consequence(127,new WordEnum ("Spread",&(*mess)[162], BLOT_AROUNDZ)));
    return csfx2;
}
static QVector<Consequence*> * fx2ClkDelay(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(122,new WordEnum ("FeedBack",&(*mess)[157], BLOT_STANDARD)));
    csfx2->append(new Consequence(123,new WordEnum ("Cutoff",&(*mess)[158], BLOT_STANDARD)));
    csfx2->append(new Consequence(124,new WordEnum ("Polarity",&(*mess)[161], BLOT_POLARITY)));
    csfx2->append(new Consequence(127,new WordEnum ("Spread",&(*mess)[162], BLOT_AROUNDZ)));
    csfx2->append(new Consequence(128,new WordEnum ("Length",&(*mess)[163], BLOT_DL_LENGTH)));
    return csfx2;
}
static QVector<Consequence*> * fx2Reverb(std::vector<uchar> * mess){
    QVector<Consequence*> * csfx2 = new QVector<Consequence*>();
    csfx2->append(new Consequence(118,new WordEnum ("Size",&(*mess)[153], BLOT_STANDARD)));
    csfx2->append(new Consequence(119,new WordEnum ("Shape",&(*mess)[154], BLOT_BYPASS)));
    csfx2->append(new Consequence(120,new WordEnum ("Decay",&(*mess)[155], BLOT_BYPASS)));
    csfx2->append(new Consequence(123,new WordEnum ("LowPass",&(*mess)[158], BLOT_BYPASS)));
    csfx2->append(new Consequence(124,new WordEnum ("HighPass",&(*mess)[159], BLOT_BYPASS)));
    csfx2->append(new Consequence(125,new WordEnum ("Diffusion",&(*mess)[160], BLOT_BYPASS)));
    csfx2->append(new Consequence(126,new WordEnum ("Damping",&(*mess)[161], BLOT_BYPASS)));
    return csfx2;
}
static QVector<Consequence*> * getfx1List(int i,std::vector<uchar> * mess){
    switch(i){
        case 0:
            return fx1Off(mess);
        case 1:
            return fx1Chorus(mess);
        case 2:
            return fx1Flanger(mess);
        case 3:
            return fx1Phaser(mess);
        case 4:
            return fx1Overdrive(mess);
        case 5:
            return fx1TripleFX(mess);
        default:
            return NULL;
    }
}
static QVector<Consequence*> * getfx2List(int i,std::vector<uchar> * mess){
    switch(i){
        case 0:
            return fx2Off(mess);
        case 1:
            return fx2Chorus(mess);
        case 2:
            return fx2Flanger(mess);
        case 3:
            return fx2Phaser(mess);
        case 4:
            return fx2Overdrive(mess);
        case 5:
            return fx2TripleFX(mess);
        case 6:
            return fx2Delay(mess);
        case 7:
            return fx2ClkDelay(mess);
        case 8:
            return fx2Reverb(mess);
        default:
            return NULL;
    }
}

void DumpInstrument::setDataContent(){

/*0*/      addParametre(new WordEnum("Oct.",&_message[8], BLOT_OSC_OCTAVE),0,1);
/*1*/      addParametre(new WordEnum("Semi",&_message[9], BLOT_OSC_SEMITONE),0,2);
/*2*/      addParametre(new WordEnum("Det",&_message[10], BLOT_AROUNDZ),0,3);
/*3*/      addParametre(new WordEnum("Bend",&_message[11], BLOT_OSC_BENDRANGE),0,4);
/*4*/      addParametre(new WordEnum("Ktr",&_message[12], BLOT_KEYTRACK),0,5);
/*5*/      addParametre(new WordEnum("FM Src",&_message[13], BLOT_FM_SOURCES),0,6);
/*6*/      addParametre(new WordEnum("FM Amount",&_message[14], BLOT_STANDARD),0,7);
/*7*/      addParametre(new WordEnum("Shape",&_message[15], BLOT_OSC_SHAPES12),0,8);
/*8*/      addParametre(new WordEnum("PulseWidth",&_message[16], BLOT_STANDARD),0,9);
/*9*/      addParametre(new WordEnum("PWM Src",&_message[17], BLOT_OSC_PWM_SOURCE),0,10);
/*10*/     addParametre(new WordEnum("PWM Amount",&_message[18], BLOT_STANDARD),0,11);
/*11*/     addParametre(new WordEnum("Limit",&_message[21], BLOT_SWITCH),0,14);
/*12*/     addParametre(new WordEnum("Brill",&_message[23], BLOT_STANDARD),0,16);
/*13*/     addParametre(new WordEnum("Oct.",&_message[24], BLOT_OSC_OCTAVE),0,17);
/*14*/     addParametre(new WordEnum("Semi",&_message[25], BLOT_OSC_SEMITONE),0,18);
/*15*/     addParametre(new WordEnum("Det",&_message[26], BLOT_AROUNDZ),0,19);
/*16*/     addParametre(new WordEnum("Bend",&_message[27], BLOT_OSC_BENDRANGE),0,20);
/*17*/     addParametre(new WordEnum("Ktr",&_message[28], BLOT_KEYTRACK),0,21);
/*18*/     addParametre(new WordEnum("FM Src",&_message[29], BLOT_FM_SOURCES),0,22);
/*19*/     addParametre(new WordEnum("FM Amnt",&_message[30], BLOT_STANDARD),0,23);
/*20*/     addParametre(new WordEnum("Shape",&_message[31], BLOT_OSC_SHAPES12),0,24);
/*21*/     addParametre(new WordEnum("PulseWidth",&_message[32], BLOT_STANDARD),0,25);
/*22*/     addParametre(new WordEnum("PWM src",&_message[33], BLOT_OSC_PWM_SOURCE),0,26);
/*23*/     addParametre(new WordEnum("PWM amnt",&_message[34], BLOT_STANDARD),0,27);
/*24*/     addParametre(new WordEnum("Limit",&_message[37], BLOT_SWITCH),0,30);
/*25*/     addParametre(new WordEnum("Brill",&_message[39], BLOT_STANDARD),0,32);
/*26*/     addParametre(new WordEnum("Oct",&_message[40], BLOT_OSC_OCTAVE),0,33);
/*27*/     addParametre(new WordEnum("Semi",&_message[41], BLOT_OSC_SEMITONE),0,34);
/*28*/     addParametre(new WordEnum("Det",&_message[42], BLOT_AROUNDZ),0,35);
/*29*/     addParametre(new WordEnum("Bend",&_message[43], BLOT_OSC_BENDRANGE),0,36);
/*30*/     addParametre(new WordEnum("Ktrk",&_message[44], BLOT_KEYTRACK),0,37);
/*31*/     addParametre(new WordEnum("FM Src",&_message[45], BLOT_FM_SOURCES),0,38);
/*32*/     addParametre(new WordEnum("FM Amount",&_message[46], BLOT_STANDARD),0,39);
/*33*/     addParametre(new WordEnum("Shape",&_message[47], BLOT_OSC_SHAPES12),0,40);
/*34*/     addParametre(new WordEnum("PulseWidth",&_message[48], BLOT_STANDARD),0,41);
/*35*/     addParametre(new WordEnum("PWM Src",&_message[49], BLOT_OSC_PWM_SOURCE),0,42);
/*36*/     addParametre(new WordEnum("PWM Amount",&_message[50], BLOT_STANDARD),0,43);
/*37*/     addParametre(new WordEnum("Sync",&_message[56], BLOT_SWITCH),0,49);
/*38*/     addParametre(new WordEnum("Brill",&_message[55], BLOT_STANDARD),0,48);
/*39*/     addParametre(new WordEnum("Mod Src",&_message[57], BLOT_MODULATION_SRC),0,50);
/*40*/     addParametre(new WordEnum("Mod Amnt",&_message[58], BLOT_AROUNDZ),0,51);
/*41*/     addParametre(new WordEnum("switch",&_message[60], BLOT_SWITCH),0,53);
/*42*/     addParametre(new WordEnum("Mode",&_message[63], BLOT_GLIDEMODE),0,56);
/*43*/     addParametre(new WordEnum("Rate",&_message[64], BLOT_STANDARD),0,57);

/*44*/     addParametre(new WordEnum("poly",&_message[65], BLOT_SWITCH,1,0),0,58);
/*45*/     addParametre(new WordEnum("Uni",&_message[65], BLOT_POLYPHONY,3,4),0,58);

/*46*/     addParametre(new WordEnum("Det",&_message[66], BLOT_STANDARD),0,59);
/*47*/     addParametre(new WordEnum("Lev",&_message[68], BLOT_STANDARD),0,61);
/*48*/     addParametre(new WordEnum("Bal",&_message[69], BLOT_AROUNDZ),0,62);
/*49*/     addParametre(new WordEnum("Lev",&_message[70], BLOT_STANDARD),0,63);
/*50*/     addParametre(new WordEnum("Bal",&_message[71], BLOT_AROUNDZ),0,64);
/*51*/     addParametre(new WordEnum("Lev",&_message[72], BLOT_STANDARD),0,65);
/*52*/     addParametre(new WordEnum("Bal",&_message[73], BLOT_AROUNDZ),0,66);
/*53*/     addParametre(new WordEnum("Lev",&_message[74], BLOT_STANDARD),0,67);
/*54*/     addParametre(new WordEnum("Bal",&_message[75], BLOT_AROUNDZ),0,68);
/*55*/     addParametre(new WordEnum("Col",&_message[76], BLOT_STANDARD),0,69);
/*56*/     addParametre(new WordEnum("Lev",&_message[78], BLOT_STANDARD),0,71);
/*57*/     addParametre(new WordEnum("Bal",&_message[79], BLOT_AROUNDZ),0,72);
/*58*/     addParametre(new WordEnum("Type",&_message[84], BLOT_FILTER_TYPE),0,77);
/*59*/     addParametre(new WordEnum("Cut",&_message[85], BLOT_STANDARD),0,78);
/*60*/     addParametre(new WordEnum("Reso",&_message[87], BLOT_STANDARD),0,80);
/*61*/     addParametre(new WordEnum("Drive",&_message[88], BLOT_STANDARD),0,81);
/*62*/     addParametre(new WordEnum("Curve",&_message[89], BLOT_FILTER_DRIVE),0,82);
/*63*/     addParametre(new WordEnum("Ktrk",&_message[93], BLOT_KEYTRACK),0,86);
/*64*/     addParametre(new WordEnum("Env.Amnt",&_message[94], BLOT_STANDARD),0,87);
/*65*/     addParametre(new WordEnum("Env.Veloc",&_message[95], BLOT_STANDARD),0,88);
/*66*/     addParametre(new WordEnum("Mod.Src",&_message[96], BLOT_MODULATION_SRC),0,89);
/*67*/     addParametre(new WordEnum("Mod.Amnt",&_message[97], BLOT_AROUNDZ),0,90);
/*68*/     addParametre(new WordEnum("FM.Src",&_message[98], BLOT_FM_SOURCES),0,91);
/*69*/     addParametre(new WordEnum("FM.Amnt",&_message[99], BLOT_STANDARD),0,92);
/*70*/     addParametre(new WordEnum("Pan",&_message[100], BLOT_AROUNDZ),0,93);
/*71*/     addParametre(new WordEnum("PanMod.Src",&_message[101], BLOT_MODULATION_SRC),0,94);
/*72*/     addParametre(new WordEnum("PanMod.Amnt",&_message[102], BLOT_AROUNDZ),0,95);
/*73*/     addParametre(new WordEnum("Type",&_message[104], BLOT_FILTER_TYPE),0,97);
/*74*/     addParametre(new WordEnum("Cut",&_message[105], BLOT_STANDARD),0,98);
/*75*/     addParametre(new WordEnum("Reso",&_message[107], BLOT_STANDARD),0,100);
/*76*/     addParametre(new WordEnum("Drive",&_message[108], BLOT_STANDARD),0,101);
/*77*/     addParametre(new WordEnum("Curve",&_message[109], BLOT_FILTER_DRIVE),0,102);
/*78*/     addParametre(new WordEnum("Ktrk",&_message[113], BLOT_KEYTRACK),0,106);
/*79*/     addParametre(new WordEnum("Env.Amnt",&_message[114], BLOT_AROUNDZ),0,107);
/*80*/     addParametre(new WordEnum("Env.Veloc",&_message[115], BLOT_AROUNDZ),0,108);
/*81*/     addParametre(new WordEnum("Mod.Src",&_message[116], BLOT_MODULATION_SRC),0,109);
/*82*/     addParametre(new WordEnum("Mod.Amnt",&_message[117], BLOT_AROUNDZ),0,110);
/*83*/     addParametre(new WordEnum("FM.Src",&_message[118], BLOT_FM_SOURCES),0,111);
/*84*/     addParametre(new WordEnum("FM.Amnt",&_message[119], BLOT_STANDARD),0,112);
/*85*/     addParametre(new WordEnum("Pan",&_message[120], BLOT_AROUNDZ),0,113);
/*86*/     addParametre(new WordEnum("PanMod.Src",&_message[121], BLOT_MODULATION_SRC),0,114);
/*87*/     addParametre(new WordEnum("PanMod.Amnt",&_message[122], BLOT_AROUNDZ),0,115);
/*88*/     addParametre(new WordEnum("Filter Routing",&_message[124], BLOT_ROUTING),0,117);
/*89*/     addParametre(new WordEnum("Vol",&_message[128], BLOT_STANDARD),0,121);
/*90*/     addParametre(new WordEnum("Veloc",&_message[129], BLOT_AROUNDZ),0,122);
/*91*/     addParametre(new WordEnum("Src",&_message[130], BLOT_MODULATION_SRC),0,123);
/*92*/     addParametre(new WordEnum("Amnt",&_message[131], BLOT_AROUNDZ),0,124);
/*93*/     addParametre(new WordEnum("Type",&_message[135], BLOT_FX1),1,0);
/*94*/     addParametre(new WordEnum("Mix",&_message[136], BLOT_STANDARD),1,1);
/*95*/     addParametre(new WordEnum("P01",&_message[137], BLOT_STANDARD),1,2);
/*96*/     addParametre(new WordEnum("P02",&_message[138], BLOT_STANDARD),1,3);
/*97*/     addParametre(new WordEnum("P03",&_message[139], BLOT_STANDARD),1,4);
/*98*/     addParametre(new WordEnum("P04",&_message[140], BLOT_STANDARD),1,5);
/*99*/     addParametre(new WordEnum("P05",&_message[141], BLOT_STANDARD),1,6);
/*100*/    addParametre(new WordEnum("P06",&_message[142], BLOT_STANDARD),1,7);
/*101*/    addParametre(new WordEnum("P07",&_message[143], BLOT_STANDARD),1,8);
/*102*/    addParametre(new WordEnum("P08",&_message[144], BLOT_STANDARD),1,9);
/*103*/    addParametre(new WordEnum("P09",&_message[145], BLOT_STANDARD),1,10);
/*104*/    addParametre(new WordEnum("P10",&_message[146], BLOT_STANDARD),1,11);
/*105*/    addParametre(new WordEnum("P11",&_message[147], BLOT_STANDARD),1,12);
/*106*/    addParametre(new WordEnum("P12",&_message[148], BLOT_STANDARD),1,13);
/*107*/    addParametre(new WordEnum("P13",&_message[149], BLOT_STANDARD),1,14);
/*108*/    addParametre(new WordEnum("P14",&_message[150], BLOT_STANDARD),1,15);
/*109*/    addParametre(new WordEnum("Type",&_message[151], BLOT_FX2),1,16);
/*110*/    addParametre(new WordEnum("Mix",&_message[152], BLOT_STANDARD),1,17);
/*111*/    addParametre(new WordEnum("P01",&_message[153], BLOT_STANDARD),1,18);
/*112*/    addParametre(new WordEnum("P02",&_message[154], BLOT_STANDARD),1,19);
/*113*/    addParametre(new WordEnum("P03",&_message[155], BLOT_STANDARD),1,20);
/*114*/    addParametre(new WordEnum("P04",&_message[156], BLOT_STANDARD),1,21);
/*115*/    addParametre(new WordEnum("P05",&_message[157], BLOT_STANDARD),1,22);
/*116*/    addParametre(new WordEnum("P06",&_message[158], BLOT_STANDARD),1,23);
/*117*/    addParametre(new WordEnum("P07",&_message[159], BLOT_STANDARD),1,24);
/*118*/    addParametre(new WordEnum("P08",&_message[160], BLOT_STANDARD),1,25);
/*119*/    addParametre(new WordEnum("P09",&_message[161], BLOT_STANDARD),1,26);
/*120*/    addParametre(new WordEnum("P10",&_message[162], BLOT_STANDARD),1,27);
/*121*/    addParametre(new WordEnum("P11",&_message[163], BLOT_STANDARD),1,28);
/*122*/    addParametre(new WordEnum("P12",&_message[164], BLOT_STANDARD),1,29);
/*123*/    addParametre(new WordEnum("P13",&_message[165], BLOT_STANDARD),1,30);
/*124*/    addParametre(new WordEnum("P14",&_message[166], BLOT_STANDARD),1,31);
/*125*/    addParametre(new WordEnum("Shape",&_message[167], BLOT_LFO_SHAPES),1,32);
/*126*/    addParametre(new WordEnum("Speed",&_message[168], BLOT_STANDARD),1,33);
/*127*/    addParametre(new WordEnum("Sync",&_message[170], BLOT_SWITCH),1,35);
/*128*/    addParametre(new WordEnum("Clck",&_message[171], BLOT_SWITCH),1,36);
/*129*/    addParametre(new WordEnum("Phase",&_message[172], BLOT_PHASE),1,37);
/*130*/    addParametre(new WordEnum("Delay",&_message[173], BLOT_STANDARD),1,38);
/*131*/    addParametre(new WordEnum("Fade",&_message[174], BLOT_AROUNDZ),1,39);
/*132*/    addParametre(new WordEnum("Ktrk",&_message[177], BLOT_KEYTRACK),1,42);
/*133*/    addParametre(new WordEnum("Shape",&_message[179], BLOT_LFO_SHAPES),1,44);
/*134*/    addParametre(new WordEnum("Speed",&_message[180], BLOT_STANDARD),1,45);
/*135*/    addParametre(new WordEnum("Sync",&_message[182], BLOT_SWITCH),1,47);
/*136*/    addParametre(new WordEnum("Clck",&_message[183], BLOT_SWITCH),1,48);
/*137*/    addParametre(new WordEnum("Phase",&_message[184], BLOT_PHASE),1,49);
/*138*/    addParametre(new WordEnum("Delay",&_message[185], BLOT_STANDARD),1,50);
/*139*/    addParametre(new WordEnum("Fade",&_message[186], BLOT_AROUNDZ),1,51);
/*140*/    addParametre(new WordEnum("Keytrack",&_message[189], BLOT_KEYTRACK),1,54);
/*141*/    addParametre(new WordEnum("Shape",&_message[191], BLOT_LFO_SHAPES),1,56);
/*142*/    addParametre(new WordEnum("Speed",&_message[192], BLOT_STANDARD),1,57);
/*143*/    addParametre(new WordEnum("Sync",&_message[194], BLOT_SWITCH),1,59);
/*144*/    addParametre(new WordEnum("Clck",&_message[195], BLOT_SWITCH),1,60);
/*145*/    addParametre(new WordEnum("Phase",&_message[196], BLOT_PHASE),1,61);
/*146*/    addParametre(new WordEnum("Delay",&_message[197], BLOT_STANDARD),1,62);
/*147*/    addParametre(new WordEnum("Fade",&_message[198], BLOT_AROUNDZ),1,63);
/*148*/    addParametre(new WordEnum("Ktrk",&_message[201], BLOT_KEYTRACK),1,66);
/*149*/    addParametre(new WordEnum("Mode",&_message[203], BLOT_ENV_MODES,5,0),1,68);
/*150*/    addParametre(new WordEnum("Trigger",&_message[203], BLOT_ENV_TRIGGER,2,5),1,68);
/*151*/    addParametre(new WordEnum("Attack",&_message[206], BLOT_STANDARD),1,71);
/*152*/    addParametre(new WordEnum("Attack Level",&_message[207], BLOT_STANDARD),1,72);
/*153*/    addParametre(new WordEnum("Decay",&_message[208], BLOT_STANDARD),1,73);
/*154*/    addParametre(new WordEnum("Sustain",&_message[209], BLOT_STANDARD),1,74);
/*155*/    addParametre(new WordEnum("Decay 2",&_message[210], BLOT_STANDARD),1,75);
/*156*/    addParametre(new WordEnum("Sustain 2",&_message[211], BLOT_STANDARD),1,76);
/*157*/    addParametre(new WordEnum("Release",&_message[212], BLOT_STANDARD),1,77);
/*158*/    addParametre(new WordEnum("Mode",&_message[215], BLOT_ENV_MODES,5,0),1,80);
/*159*/    addParametre(new WordEnum("Trigger",&_message[215], BLOT_ENV_TRIGGER,2,5),1,80);
/*160*/    addParametre(new WordEnum("Attack",&_message[218], BLOT_STANDARD),1,83);
/*161*/    addParametre(new WordEnum("Attack Level",&_message[219], BLOT_STANDARD),1,84);
/*162*/    addParametre(new WordEnum("Decay",&_message[220], BLOT_STANDARD),1,85);
/*163*/    addParametre(new WordEnum("Sustain",&_message[221], BLOT_STANDARD),1,86);
/*164*/    addParametre(new WordEnum("Decay 2",&_message[222], BLOT_STANDARD),1,87);
/*165*/    addParametre(new WordEnum("Sustain 2",&_message[223], BLOT_STANDARD),1,88);
/*166*/    addParametre(new WordEnum("Release",&_message[224], BLOT_STANDARD),1,89);
/*167*/    addParametre(new WordEnum("Mode",&_message[227], BLOT_ENV_MODES,5,0),1,92);
/*168*/    addParametre(new WordEnum("Trigger",&_message[227], BLOT_ENV_TRIGGER,2,5),1,92);
/*169*/    addParametre(new WordEnum("Attack",&_message[230], BLOT_STANDARD),1,95);
/*170*/    addParametre(new WordEnum("Attack Level",&_message[231], BLOT_STANDARD),1,96);
/*171*/    addParametre(new WordEnum("Decay",&_message[232], BLOT_STANDARD),1,97);
/*172*/    addParametre(new WordEnum("Sustain",&_message[233], BLOT_STANDARD),1,98);
/*173*/    addParametre(new WordEnum("Decay 2",&_message[234], BLOT_STANDARD),1,99);
/*174*/    addParametre(new WordEnum("Sustain 2",&_message[235], BLOT_STANDARD),1,100);
/*175*/    addParametre(new WordEnum("Release",&_message[236], BLOT_STANDARD),1,101);
/*176*/    addParametre(new WordEnum("Mode",&_message[239], BLOT_ENV_MODES,5,0),1,104);
/*177*/    addParametre(new WordEnum("Trigger",&_message[239], BLOT_ENV_TRIGGER,2,5),1,104);
/*178*/    addParametre(new WordEnum("Attack",&_message[242], BLOT_STANDARD),1,107);
/*179*/    addParametre(new WordEnum("Attack Level",&_message[243], BLOT_STANDARD),1,108);
/*180*/    addParametre(new WordEnum("Decay",&_message[244], BLOT_STANDARD),1,109);
/*181*/    addParametre(new WordEnum("Sustain",&_message[245], BLOT_STANDARD),1,110);
/*182*/    addParametre(new WordEnum("Decay 2",&_message[246], BLOT_STANDARD),1,111);
/*183*/    addParametre(new WordEnum("Sustain 2",&_message[247], BLOT_STANDARD),1,112);
/*184*/    addParametre(new WordEnum("Release",&_message[248], BLOT_STANDARD),1,113);
/*185*/    addParametre(new WordEnum("Source A",&_message[252], BLOT_MODULATION_SRC),1,117);
/*186*/    addParametre(new WordEnum("Source B",&_message[253], BLOT_MODULATION_SRC),1,118);
/*187*/    addParametre(new WordEnum("Operation",&_message[254], BLOT_MODIFIER_OPS),1,119);
/*188*/    addParametre(new WordEnum("Constant",&_message[255], BLOT_AROUNDZ),1,120);
/*189*/    addParametre(new WordEnum("Source A",&_message[256], BLOT_MODULATION_SRC),1,121);
/*190*/    addParametre(new WordEnum("Source B",&_message[257], BLOT_MODULATION_SRC),1,122);
/*191*/    addParametre(new WordEnum("Operation",&_message[258], BLOT_MODIFIER_OPS),1,123);
/*192*/    addParametre(new WordEnum("Constant",&_message[259], BLOT_AROUNDZ),1,124);
/*193*/    addParametre(new WordEnum("Source A",&_message[260], BLOT_MODULATION_SRC),1,125);
/*194*/    addParametre(new WordEnum("Source B",&_message[261], BLOT_MODULATION_SRC),1,126);
/*195*/    addParametre(new WordEnum("Operation",&_message[262], BLOT_MODIFIER_OPS),1,127);
/*196*/    addParametre(new WordEnum("Constant",&_message[263], BLOT_AROUNDZ),2,0);
/*197*/    addParametre(new WordEnum("Source A",&_message[264], BLOT_MODULATION_SRC),2,1);
/*198*/    addParametre(new WordEnum("Source B",&_message[265], BLOT_MODULATION_SRC),2,2);
/*199*/    addParametre(new WordEnum("Operation",&_message[266], BLOT_MODIFIER_OPS),2,3);
/*200*/    addParametre(new WordEnum("Constant",&_message[267], BLOT_AROUNDZ),2,4);
/*201*/    addParametre(new WordEnum("Source",&_message[268], BLOT_MODULATION_SRC),2,5);
/*202*/    addParametre(new WordEnum("Destination",&_message[269], BLOT_MODULATION_DST),2,6);
/*203*/    addParametre(new WordEnum("Amount",&_message[270], BLOT_AROUNDZ),2,7);
/*204*/    addParametre(new WordEnum("Source",&_message[271], BLOT_MODULATION_SRC),2,8);
/*205*/    addParametre(new WordEnum("Destination",&_message[272], BLOT_MODULATION_DST),2,9);
/*206*/    addParametre(new WordEnum("Amount",&_message[273], BLOT_AROUNDZ),2,10);
/*207*/    addParametre(new WordEnum("Source",&_message[274], BLOT_MODULATION_SRC),2,11);
/*208*/    addParametre(new WordEnum("Destination",&_message[275], BLOT_MODULATION_DST),2,12);
/*209*/    addParametre(new WordEnum("Amount",&_message[276], BLOT_AROUNDZ),2,13);
/*210*/    addParametre(new WordEnum("Source",&_message[277], BLOT_MODULATION_SRC),2,14);
/*211*/    addParametre(new WordEnum("Destination",&_message[278], BLOT_MODULATION_DST),2,15);
/*212*/    addParametre(new WordEnum("Amount",&_message[279], BLOT_AROUNDZ),2,16);
/*213*/    addParametre(new WordEnum("Source",&_message[280], BLOT_MODULATION_SRC),2,17);
/*214*/    addParametre(new WordEnum("Destination",&_message[281], BLOT_MODULATION_DST),2,18);
/*215*/    addParametre(new WordEnum("Amount",&_message[282], BLOT_AROUNDZ),2,19);
/*216*/    addParametre(new WordEnum("Source",&_message[283], BLOT_MODULATION_SRC),2,20);
/*217*/    addParametre(new WordEnum("Destination",&_message[284], BLOT_MODULATION_DST),2,21);
/*218*/    addParametre(new WordEnum("Amount",&_message[285], BLOT_AROUNDZ),2,22);
/*219*/    addParametre(new WordEnum("Source",&_message[286], BLOT_MODULATION_SRC),2,23);
/*220*/    addParametre(new WordEnum("Destination",&_message[287], BLOT_MODULATION_DST),2,24);
/*221*/    addParametre(new WordEnum("Amount",&_message[288], BLOT_AROUNDZ),2,25);
/*222*/    addParametre(new WordEnum("Source",&_message[289], BLOT_MODULATION_SRC),2,26);
/*223*/    addParametre(new WordEnum("Destination",&_message[290], BLOT_MODULATION_DST),2,27);
/*224*/    addParametre(new WordEnum("Amount",&_message[291], BLOT_AROUNDZ),2,28);
/*225*/    addParametre(new WordEnum("Source",&_message[292], BLOT_MODULATION_SRC),2,29);
/*226*/    addParametre(new WordEnum("Destination",&_message[293], BLOT_MODULATION_DST),2,30);
/*227*/    addParametre(new WordEnum("Amount",&_message[294], BLOT_AROUNDZ),2,31);
/*228*/    addParametre(new WordEnum("Source",&_message[295], BLOT_MODULATION_SRC),2,32);
/*229*/    addParametre(new WordEnum("Destination",&_message[296], BLOT_MODULATION_DST),2,33);
/*230*/    addParametre(new WordEnum("Amount",&_message[297], BLOT_AROUNDZ),2,34);
/*231*/    addParametre(new WordEnum("Source",&_message[298], BLOT_MODULATION_SRC),2,35);
/*232*/    addParametre(new WordEnum("Destination",&_message[299], BLOT_MODULATION_DST),2,36);
/*233*/    addParametre(new WordEnum("Amount",&_message[300], BLOT_AROUNDZ),2,37);
/*234*/    addParametre(new WordEnum("Source",&_message[301], BLOT_MODULATION_SRC),2,38);
/*235*/    addParametre(new WordEnum("Destination",&_message[302], BLOT_MODULATION_DST),2,39);
/*236*/    addParametre(new WordEnum("Amount",&_message[303], BLOT_AROUNDZ),2,40);
/*237*/    addParametre(new WordEnum("Source",&_message[304], BLOT_MODULATION_SRC),2,41);
/*238*/    addParametre(new WordEnum("Destination",&_message[305], BLOT_MODULATION_DST),2,42);
/*239*/    addParametre(new WordEnum("Amount",&_message[306], BLOT_AROUNDZ),2,43);
/*240*/    addParametre(new WordEnum("Source",&_message[307], BLOT_MODULATION_SRC),2,44);
/*241*/    addParametre(new WordEnum("Destination",&_message[308], BLOT_MODULATION_DST),2,45);
/*242*/    addParametre(new WordEnum("Amount",&_message[309], BLOT_AROUNDZ),2,46);
/*243*/    addParametre(new WordEnum("Source",&_message[310], BLOT_MODULATION_SRC),2,47);
/*244*/    addParametre(new WordEnum("Destination",&_message[311], BLOT_MODULATION_DST),2,48);
/*245*/    addParametre(new WordEnum("Amount",&_message[312], BLOT_AROUNDZ),2,49);
/*246*/    addParametre(new WordEnum("Source",&_message[313], BLOT_MODULATION_SRC),2,50);
/*247*/    addParametre(new WordEnum("Destination",&_message[314], BLOT_MODULATION_DST),2,51);
/*248*/    addParametre(new WordEnum("Amount",&_message[315], BLOT_AROUNDZ),2,52);
/*249*/    addParametre(new WordEnum("Mode",&_message[318], BLOT_ARPMODE),2,55);
/*250*/    addParametre(new WordEnum("Pattern",&_message[319], BLOT_ARPPATTERN),2,56);
/*251*/    addParametre(new WordEnum("Clock",&_message[321], BLOT_ARPCLOCK),2,58);
/*252*/    addParametre(new WordEnum("Length",&_message[322], BLOT_ARPLENGTH),2,59);
/*253*/    addParametre(new WordEnum("Octave",&_message[323], BLOT_ARPOCTAVE),2,60);
/*254*/    addParametre(new WordEnum("Direction",&_message[324], BLOT_ARPDIRECTION),2,61);
/*255*/    addParametre(new WordEnum("Sort Order",&_message[325], BLOT_ARPSORT),2,62);
/*256*/    addParametre(new WordEnum("Velocity",&_message[326], BLOT_ARPVELOCITY),2,63);
/*257*/    addParametre(new WordEnum("Timing Factor",&_message[327], BLOT_STANDARD),2,64);
/*258*/    addParametre(new WordEnum("Ptn Reset",&_message[329], BLOT_SWITCH),2,66);
/*259*/    addParametre(new WordEnum("Ptn Length",&_message[330], BLOT_ARPLENGTH),2,67);
/*260*/    addParametre(new WordEnum("Tempo",&_message[333], BLOT_TEMPO),2,70);
/*261*/    addParametre(new WordEnum("Step",&_message[335], BLOT_ARP_PTNSTEP,3,4),2,71);
/*262*/    addParametre(new WordEnum("Glide",&_message[335], BLOT_SWITCH,1,3),2,71);
/*263*/    addParametre(new WordEnum("Accent",&_message[335], BLOT_ARP_PTNACCENT,3,0),2,71);
/*264*/    addParametre(new WordEnum("Step",&_message[336], BLOT_ARP_PTNSTEP,3,4),2,72);
/*265*/    addParametre(new WordEnum("Glide",&_message[336], BLOT_SWITCH,1,3),2,72);
/*266*/    addParametre(new WordEnum("Accent",&_message[336], BLOT_ARP_PTNACCENT,3,0),2,72);
/*267*/    addParametre(new WordEnum("Step",&_message[336], BLOT_ARP_PTNSTEP,3,4),2,73);
/*268*/    addParametre(new WordEnum("Glide",&_message[336], BLOT_SWITCH,1,3),2,73);
/*269*/    addParametre(new WordEnum("Accent",&_message[336], BLOT_ARP_PTNACCENT,3,0),2,73);
/*270*/    addParametre(new WordEnum("Step",&_message[337], BLOT_ARP_PTNSTEP,3,4),2,74);
/*271*/    addParametre(new WordEnum("Glide",&_message[337], BLOT_SWITCH,1,3),2,74);
/*272*/    addParametre(new WordEnum("Accent",&_message[337], BLOT_ARP_PTNACCENT,3,0),2,74);
/*273*/    addParametre(new WordEnum("Step",&_message[338], BLOT_ARP_PTNSTEP,3,4),2,75);
/*274*/    addParametre(new WordEnum("Glide",&_message[338], BLOT_SWITCH,1,3),2,75);
/*275*/    addParametre(new WordEnum("Accent",&_message[338], BLOT_ARP_PTNACCENT,3,0),2,75);
/*276*/    addParametre(new WordEnum("Step",&_message[339], BLOT_ARP_PTNSTEP,3,4),2,76);
/*277*/    addParametre(new WordEnum("Glide",&_message[339], BLOT_SWITCH,1,3),2,76);
/*278*/    addParametre(new WordEnum("Accent",&_message[339], BLOT_ARP_PTNACCENT,3,0),2,76);
/*279*/    addParametre(new WordEnum("Step",&_message[340], BLOT_ARP_PTNSTEP,3,4),2,77);
/*280*/    addParametre(new WordEnum("Glide",&_message[340], BLOT_SWITCH,1,3),2,77);
/*281*/    addParametre(new WordEnum("Accent",&_message[340], BLOT_ARP_PTNACCENT,3,0),2,77);
/*282*/    addParametre(new WordEnum("Step",&_message[341], BLOT_ARP_PTNSTEP,3,4),2,78);
/*283*/    addParametre(new WordEnum("Glide",&_message[341], BLOT_SWITCH,1,3),2,78);
/*284*/    addParametre(new WordEnum("Accent",&_message[341], BLOT_ARP_PTNACCENT,3,0),2,78);
/*285*/    addParametre(new WordEnum("Step",&_message[342], BLOT_ARP_PTNSTEP,3,4),2,79);
/*286*/    addParametre(new WordEnum("Glide",&_message[342], BLOT_SWITCH,1,3),2,79);
/*287*/    addParametre(new WordEnum("Accent",&_message[342], BLOT_ARP_PTNACCENT,3,0),2,79);
/*288*/    addParametre(new WordEnum("Step",&_message[343], BLOT_ARP_PTNSTEP,3,4),2,80);
/*289*/    addParametre(new WordEnum("Glide",&_message[343], BLOT_SWITCH,1,3),2,80);
/*290*/    addParametre(new WordEnum("Accent",&_message[343], BLOT_ARP_PTNACCENT,3,0),2,80);
/*291*/    addParametre(new WordEnum("Step",&_message[344], BLOT_ARP_PTNSTEP,3,4),2,81);
/*292*/    addParametre(new WordEnum("Glide",&_message[344], BLOT_SWITCH,1,3),2,81);
/*293*/    addParametre(new WordEnum("Accent",&_message[344], BLOT_ARP_PTNACCENT,3,0),2,81);
/*294*/    addParametre(new WordEnum("Step",&_message[345], BLOT_ARP_PTNSTEP,3,4),2,82);
/*295*/    addParametre(new WordEnum("Glide",&_message[345], BLOT_SWITCH,1,3),2,82);
/*296*/    addParametre(new WordEnum("Accent",&_message[345], BLOT_ARP_PTNACCENT,3,0),2,82);
/*297*/    addParametre(new WordEnum("Step",&_message[346], BLOT_ARP_PTNSTEP,3,4),2,83);
/*298*/    addParametre(new WordEnum("Glide",&_message[346], BLOT_SWITCH,1,3),2,83);
/*299*/    addParametre(new WordEnum("Accent",&_message[346], BLOT_ARP_PTNACCENT,3,0),2,83);
/*300*/    addParametre(new WordEnum("Step",&_message[347], BLOT_ARP_PTNSTEP,3,4),2,84);
/*301*/    addParametre(new WordEnum("Glide",&_message[347], BLOT_SWITCH,1,3),2,84);
/*302*/    addParametre(new WordEnum("Accent",&_message[347], BLOT_ARP_PTNACCENT,3,0),2,84);
/*303*/    addParametre(new WordEnum("Step",&_message[348], BLOT_ARP_PTNSTEP,3,4),2,85);
/*304*/    addParametre(new WordEnum("Glide",&_message[348], BLOT_SWITCH,1,3),2,85);
/*305*/    addParametre(new WordEnum("Accent",&_message[348], BLOT_ARP_PTNACCENT,3,0),2,85);
/*306*/    addParametre(new WordEnum("Step",&_message[349], BLOT_ARP_PTNSTEP,3,4),2,86);
/*307*/    addParametre(new WordEnum("Glide",&_message[349], BLOT_SWITCH,1,3),2,86);
/*308*/    addParametre(new WordEnum("Accent",&_message[349], BLOT_ARP_PTNACCENT,3,0),2,86);
/*309*/    addParametre(new WordEnum("Timing",&_message[350], BLOT_ARP_PTNTIME,3,0),2,87);
/*310*/    addParametre(new WordEnum("Length",&_message[350], BLOT_ARP_PTNLENGTH,3,4),2,87);
/*311*/    addParametre(new WordEnum("Timing",&_message[351], BLOT_ARP_PTNTIME,3,0),2,88);
/*312*/    addParametre(new WordEnum("Length",&_message[351], BLOT_ARP_PTNLENGTH,3,4),2,88);
/*313*/    addParametre(new WordEnum("Timing",&_message[352], BLOT_ARP_PTNTIME,3,0),2,89);
/*314*/    addParametre(new WordEnum("Length",&_message[352], BLOT_ARP_PTNLENGTH,3,4),2,89);
/*315*/    addParametre(new WordEnum("Timing",&_message[353], BLOT_ARP_PTNTIME,3,0),2,90);
/*316*/    addParametre(new WordEnum("Length",&_message[353], BLOT_ARP_PTNLENGTH,3,4),2,90);
/*317*/    addParametre(new WordEnum("Timing",&_message[354], BLOT_ARP_PTNTIME,3,0),2,91);
/*318*/    addParametre(new WordEnum("Length",&_message[354], BLOT_ARP_PTNLENGTH,3,4),2,91);
/*319*/    addParametre(new WordEnum("Timing",&_message[355], BLOT_ARP_PTNTIME,3,0),2,92);
/*320*/    addParametre(new WordEnum("Length",&_message[355], BLOT_ARP_PTNLENGTH,3,4),2,92);
/*321*/    addParametre(new WordEnum("Timing",&_message[356], BLOT_ARP_PTNTIME,3,0),2,93);
/*322*/    addParametre(new WordEnum("Length",&_message[356], BLOT_ARP_PTNLENGTH,3,4),2,93);
/*323*/    addParametre(new WordEnum("Timing",&_message[357], BLOT_ARP_PTNTIME,3,0),2,94);
/*324*/    addParametre(new WordEnum("Length",&_message[357], BLOT_ARP_PTNLENGTH,3,4),2,94);
/*325*/    addParametre(new WordEnum("Timing",&_message[358], BLOT_ARP_PTNTIME,3,0),2,95);
/*326*/    addParametre(new WordEnum("Length",&_message[358], BLOT_ARP_PTNLENGTH,3,4),2,95);
/*327*/    addParametre(new WordEnum("Timing",&_message[359], BLOT_ARP_PTNTIME,3,0),2,96);
/*328*/    addParametre(new WordEnum("Length",&_message[359], BLOT_ARP_PTNLENGTH,3,4),2,96);
/*329*/    addParametre(new WordEnum("Timing",&_message[360], BLOT_ARP_PTNTIME,3,0),2,97);
/*330*/    addParametre(new WordEnum("Length",&_message[360], BLOT_ARP_PTNLENGTH,3,4),2,97);
/*331*/    addParametre(new WordEnum("Timing",&_message[361], BLOT_ARP_PTNTIME,3,0),2,98);
/*332*/    addParametre(new WordEnum("Length",&_message[361], BLOT_ARP_PTNLENGTH,3,4),2,98);
/*333*/    addParametre(new WordEnum("Timing",&_message[362], BLOT_ARP_PTNTIME,3,0),2,99);
/*334*/    addParametre(new WordEnum("Length",&_message[362], BLOT_ARP_PTNLENGTH,3,4),2,99);
/*335*/    addParametre(new WordEnum("Timing",&_message[363], BLOT_ARP_PTNTIME,3,0),2,100);
/*336*/    addParametre(new WordEnum("Length",&_message[363], BLOT_ARP_PTNLENGTH,3,4),2,100);
/*337*/    addParametre(new WordEnum("Timing",&_message[364], BLOT_ARP_PTNTIME,3,0),2,101);
/*338*/    addParametre(new WordEnum("Length",&_message[364], BLOT_ARP_PTNLENGTH,3,4),2,101);
/*339*/    addParametre(new WordEnum("Timing",&_message[365], BLOT_ARP_PTNTIME,3,0),2,102);
/*340*/    addParametre(new WordEnum("Length",&_message[365], BLOT_ARP_PTNLENGTH,3,4),2,102);
/*341*/    addParametre(new WordEnum("CHAR 1",&_message[370], BLOT_CHARZ),2,107);
/*342*/    addParametre(new WordEnum("CHAR 2",&_message[371], BLOT_CHARZ),2,108);
/*343*/    addParametre(new WordEnum("CHAR 3",&_message[372], BLOT_CHARZ),2,109);
/*344*/    addParametre(new WordEnum("CHAR 4",&_message[373], BLOT_CHARZ),2,110);
/*345*/    addParametre(new WordEnum("CHAR 5",&_message[374], BLOT_CHARZ),2,111);
/*346*/    addParametre(new WordEnum("CHAR 6",&_message[375], BLOT_CHARZ),2,112);
/*347*/    addParametre(new WordEnum("CHAR 7",&_message[376], BLOT_CHARZ),2,113);
/*348*/    addParametre(new WordEnum("CHAR 8",&_message[377], BLOT_CHARZ),2,114);
/*349*/    addParametre(new WordEnum("CHAR 9",&_message[378], BLOT_CHARZ),2,115);
/*350*/    addParametre(new WordEnum("CHAR 10",&_message[379], BLOT_CHARZ),2,116);
/*351*/    addParametre(new WordEnum("CHAR 11",&_message[380], BLOT_CHARZ),2,117);
/*352*/    addParametre(new WordEnum("CHAR 12",&_message[381], BLOT_CHARZ),2,118);
/*353*/    addParametre(new WordEnum("CHAR 13",&_message[382], BLOT_CHARZ),2,119);
/*354*/    addParametre(new WordEnum("CHAR 14",&_message[383], BLOT_CHARZ),2,120);
/*355*/    addParametre(new WordEnum("CHAR 15",&_message[384], BLOT_CHARZ),2,121);
/*356*/    addParametre(new WordEnum("CHAR 16",&_message[385], BLOT_CHARZ),2,122);
/*357*/    addParametre(new WordEnum("Category",&_message[386], BLOT_CATEGORIES),2,123);

         QVector<WordMutation*> * vConsequences1 = new QVector<WordMutation*>();
        QVector<WordMutation*> * vConsequences2 = new QVector<WordMutation*>();
        for(int i(0);i<9;i++){
            QVector<Consequence*> * f1 =getfx1List(i,&_message) ;
            QVector<Consequence*> * f2 =getfx2List(i,&_message);
            if(f1!=NULL){
                vConsequences1->append( new WordMutation(i,f1));
            }
            if(f2!=NULL){
                vConsequences2->append( new WordMutation(i,f2));
            }
        }

        _replacers->append(new WReplacer(_mots.at(100),  vConsequences1));
        _replacers->append(new WReplacer(_mots.at(116),  vConsequences2));

}

int DumpInstrument::getChannel(){

    if(getWordValue(5)==0x7f)
        return getWordValue(6);
    else return (-1);
}

Instrument DumpInstrument::createInstrument(){

    QVector<Parametre> lst  ;
    for(int i(0); i< count() ;i++)
    {
        ParametreCom  pc = createParam(i);
        Parametre p(pc.getValueMgr(),i);
        lst.append(p);
    }
    Instrument *inst = new Instrument(getEmbeddedName(),lst);
    return *inst;
}

Parametre DumpInstrument::createParametre(int i){
    ParametreCom * pc = _Parametres.at(i);
    Parametre p(pc->getValueMgr(),pc->getId());
    return p;
}

void DumpInstrument::setInstrument(const Instrument* i) const{

    if(         ! i->count() == _Parametres.count()
            ||  ! i->count())
    return;

    foreach(ParametreCom * p ,_Parametres){
        try{
            int value = i->getValue(p->getId());
            p->setParamValue(value);
        }catch(...){

        }
    }
}


std::vector<uchar> * DumpInstrument::getPMessage(const Parametre * p,int macid,int chid)
{
    //THISISUGLYTHEMOST
    ParametreCom * par  = getParam(p->getID());
    par->setParamValue(p->getValue());

    QVector<ParametreCom *>ps= getParams(p->getID());

    ParametreCom * mw = new ParametreCom(ps.first()->_ad1,ps.first()->_ad2);

    foreach(ParametreCom * pc ,ps){
        WordWriter *w= new WordWriter(pc->_word, &mw->_message[8]);
        mw->appenWord(w);
        w->setValue(pc->getValue());
    }

    return mw->getMessage(macid,chid);
}


