#include "BlofeldEnums.h"

BlofeldTypesEnum::BlofeldTypesEnum(){



 /*0*/       AddEnum(blotype_Standard());
 /*1*/       AddEnum(blotype_osc_shapes12()) ;
 /*2*/       AddEnum(blotype_osc_shapes3()) ;
 /*3*/       AddEnum(blotype_osc_pwm_source()) ;
 /*4*/       AddEnum(blotype_osc_octave()) ;
 /*5*/       AddEnum(blotype_osc_semitone()) ;
 /*6*/       AddEnum(blotype_osc_bendrange()) ;
 /*7*/       AddEnum(blotype_polyphony()) ;
 /*8*/       AddEnum(blotype_glidemode()) ;
 /*9*/       AddEnum(blotype_filter_type()) ;
 /*10*/      AddEnum(blotype_filter_drive()) ;
 /*11*/      AddEnum(blotype_lfo_shapes()) ;
 /*12*/      AddEnum(blotype_env_modes()) ;
 /*13*/      AddEnum(blotype_env_trigger()) ;
 /*14*/      AddEnum(blotype_modulation_src()) ;
 /*15*/      AddEnum(blotype_modulation_dst()) ;
 /*16*/      AddEnum(blotype_modifier_ops()) ;
 /*17*/      AddEnum(blotype_fm_sources()) ;
 /*18*/      AddEnum(blotype_fx1() );
 /*19*/      AddEnum(blotype_fx2()) ;
 /*20*/      AddEnum(blotype_fx_driveCurve());
 /*21*/      AddEnum(blotype_InstruCat());
 /*22*/      AddEnum(blotype_switch()) ;
 /*23*/      AddEnum(blotype_FilterRouting());
 /*24*/      AddEnum(blotype_AroundZero());
 /*25*/      AddEnum(blotype_Keytrack());
 /*26*/      AddEnum(blotype_Phase());
 /*27*/      AddEnum(blotype_Chars());
 /*28*/      AddEnum(blotype_arp_mode());
 /*29*/      AddEnum(blotype_arp_clock());
 /*30*/      AddEnum(blotype_arp_tempo());
 /*31*/      AddEnum(blotype_arp_pattern());
 /*32*/      AddEnum(blotype_arp_direction());
 /*33*/      AddEnum(blotype_arp_octave());
 /*34*/      AddEnum(blotype_arp_length());
 /*35*/      AddEnum(blotype_arp_sort());
 /*36*/      AddEnum(blotype_arp_velocity());
 /*37*/      AddEnum(blotype_arp_ptn_step());
 /*38*/      AddEnum(blotype_arp_ptn_accent());
 /*39*/      AddEnum(blotype_arp_ptntiming());
 /*40*/      AddEnum(blotype_arp_ptnlength());
 /*41*/       AddEnum(blotype_Channels());
 /*42*/       AddEnum(blotype_bypass());
 /*43*/       AddEnum(blotype_polarity());
 /*44*/       AddEnum(blotype_dl_length());
 /*45*/       AddEnum(blotype_bank());

    /*46*/       AddEnum(blotype_multi_transpose());
/*47*/       AddEnum(blotype_multi_channel());
/*48*/       AddEnum(blotype_multi_note());
/*49*/       AddEnum(blotype_glob_popup());
/*50*/       AddEnum(blotype_glob_mastune());
/*51*/       AddEnum(blotype_glob_sendCtrl());
/*52*/       AddEnum(blotype_glob_curve());
/*53*/       AddEnum(blotype_glob_ctrlnum());
/*54*/       AddEnum(blotype_glob_freebutton());
    /*55*/       AddEnum(blotype_glob_centered());
    /*56*/       AddEnum(blotype_glob_pan());
    /*57*/       AddEnum(blotype_glob_vol());

}

const SynthEnum* BlofeldTypesEnum::GetEnum(int i)const{
    if(i<0 || LesEnums.count()==0 ||  i> LesEnums.count() ){
        throw std::logic_error("L'énumération n'éxiste pas");
    }
    return LesEnums[i];
}

const SynthEnum* BlofeldTypesEnum::GetEnum(QString nom) const{

    foreach(const SynthEnum * se, LesEnums){
        if(se->_nom == nom){
            return se;
        }
    }
    throw("L'enumeration n'existe pas");
}


void BlofeldTypesEnum::AddEnum(const SynthEnum * se){

    for (int i=0;i<LesEnums.count();i++)
    {
        const SynthEnum * en = LesEnums.at(i);
        if(en->_nom.trimmed() == se->_nom.trimmed()){
            throw std::logic_error("une énumération portant ce nom existe déja");
        }
    }
    LesEnums.append(se);
}

void BlofeldTypesEnum::ReplaceEnum(const SynthEnum * se){

    for (int i=0;i<LesEnums.count();i++)
    {
        const SynthEnum *  en= LesEnums.at(i);
        if(en->_nom == se->_nom){

            LesEnums.replace(i,se);
            return;
        }
    }
    LesEnums.append(se);

}



const SynthEnum * BlofeldTypesEnum::blotype_osc_shapes12() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
        monEnum= new SynthEnum();
        monEnum->_nom= "OSC 1&2 Shapes";

        se1 = new SynthEnumElement("off",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Pulse",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Saw",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Triangle",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Sine",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Alt 1",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Alt 2",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Resonant",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Resonant2",8 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("MalletSyn",9 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Sqr-Sweep",10 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Bellish",11 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Pul-Sweep",12 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Saw-Sweep",13 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("MellowSaw",14 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Feedback",15 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Add Harm",16 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Reso 3 HP",17 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Wind Syn",18 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("High Harm",19 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Clipper",20 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Organ Syn",21 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("SquareSaw",22 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Formant 1",23 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Polated",24 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Transient",25 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("ElectricP",26 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Robotic",27 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("StrongHrm",28 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("PercOrgan",29 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("ClipSweep",30 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("ResoHarms",31 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("2 Echoes",32 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Formant 2",33 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("FmntVocal",34 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("MicroSync",35 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Micro PWM",36 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Glassy",37 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Square HP",38 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("SawSync 1",39 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("SawSync 2",40 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("SawSync 3",41 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("PulSync 1",42 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("PulSync 2",43 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("PulSync 3",44 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("SinSync 1",45 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("SinSync 2",46 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("SinSync 3",47 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("PWM Pulse",48 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("PWM Saw",49 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Fuzz Wave",50 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Distorted",51 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("HeavyFuzz",52 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Fuzz Sync",53 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("K+Strong1",54 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("K+Strong2",55 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("K+Strong3",56 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("1-2-3-4-5",57 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("19/twenty",58 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Wavetrip1",59 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Wavetrip2",60 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Wavetrip3",61 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Wavetrip4",62 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("MaleVoice",63 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Low Piano",64 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("ResoSweep",65 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Xmas Bell",66 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("FM Piano",67 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Fat Organ",68 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Vibes",69 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Chorus 2",70 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("True PWM",71 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("UpperWaves",72 );
        monEnum->EnumValidation(se1);

        for(int i(0);i<39;i++){
            auto s= QString("Usr WT%2d").arg(i);
            se1 = new SynthEnumElement(s,86+i );
            monEnum->EnumValidation(se1);
        }
        monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_osc_shapes3() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "OSC3 Shapes";

        se1 = new SynthEnumElement("off",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Pulse",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Saw",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Triangle",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Sine",4 );
        monEnum->EnumValidation(se1);

        monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_osc_pwm_source() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "PWM Sources";
        se1 = new SynthEnumElement("off",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 1",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO1*MW",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 2",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO2*Press",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 3",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("FilterEnv",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("AmpEnv",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Env3",8 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Env4",9 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Keytrack",10 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Velocity",11 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Rel. Velo",12 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Pressure",13 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Poly Press",14 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Pitch Bend",15 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Mod Wheel",16 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Sustain",17 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Foot Ctrl",18 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("BreathCtrl",19 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Control W",20 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Control X",21 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Control Y",22 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Control Z",23 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Unisono V.",24 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Modifier 1",25 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Modifier 2",26 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Modifier 3",27 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Modifier 4",28 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("minimum",29 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("MAXIMUM",30 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;


}
const SynthEnum * BlofeldTypesEnum::blotype_osc_octave() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "Octave";

        se1 = new SynthEnumElement("128",16 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("64",28 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("32",40);
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("16",52 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("8",64 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("4",76 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("2",88 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("1",100 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("1/2",112 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_osc_semitone() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "semitone";

    for(int i(0);i<=24;i++){

        auto s = QString("%1").arg(i-12);
        se1 = new SynthEnumElement(s,52+i );
        monEnum->EnumValidation(se1);
    }

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_osc_bendrange() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "OSC Bend Range";

    for(int i(0);i<=48;i++){

        auto s = QString("%1").arg(i-24);
        se1 = new SynthEnumElement(s,40+i );
        monEnum->EnumValidation(se1);
    }

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_polyphony() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "Unisono Modes";

    se1 = new SynthEnumElement("Off",0 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("dual",1 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("3",2 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("4",3 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("5",4 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("6",5 );
    monEnum->EnumValidation(se1);
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_glidemode() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "Glide Modes";

        se1 = new SynthEnumElement("Portamento",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("fingered P",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Glissando",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("fingered G",3 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_filter_type() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "Filter Types";

        se1 = new SynthEnumElement("Bypass",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LP 24dB",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LP 12dB",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("BP 24dB",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("BP 12dB",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("HP 24dB",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("HP 12dB",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Notch24dB",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Notch12dB",8 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Comb+",9 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Comb-",10 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("PPG LP",11 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_filter_drive() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "Drive Curves";

        se1 = new SynthEnumElement("Clipping",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Tube",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Hard",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Medium",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Soft",4);
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Pickup 1",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Pickup 2",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Rectifier",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Square",8 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Binary",9 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Overflow",10 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Sine Shaper",11 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Osc 1 Mod",12 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_lfo_shapes() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;


        monEnum= new SynthEnum();
        monEnum->_nom= "LFO Shapes";

        se1 = new SynthEnumElement("Sine",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Triangle",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Square",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Saw",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Random",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("S&H",5 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_env_modes() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
        monEnum->_nom= "Envelope Modes";

        se1 = new SynthEnumElement("ADSR",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("ADS1DS2R",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("One Shot",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Loop S1S2",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Loop All",4 );
        monEnum->EnumValidation(se1);
                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}

const SynthEnum * BlofeldTypesEnum::blotype_env_trigger() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
        monEnum->_nom= "Envelope triggers";

        se1 = new SynthEnumElement("normal",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("single",1 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}

const SynthEnum * BlofeldTypesEnum::blotype_modulation_src() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "Modulation Sources";

        se1 = new SynthEnumElement("off",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 1",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO1*MW",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 2",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO2*Press",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 3",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("FilterEnv",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("AmpEnv",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Env3",8 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Env4",9 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Keytrack",10 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Velocity",11 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Rel. Velo",12 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Pressure",13 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Poly Press",14 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Pitch Bend",15 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Mod Wheel",16 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Sustain",17 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Foot Ctrl",18 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("BreathCtrl",19 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Control W",20 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Control X",21 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Control Y",22 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Control Z",23 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Unisono V.",24 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Modifier 1",25 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Modifier 2",26 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Modifier 3",27 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Modifier 4",28 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("minimum",29 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("MAXIMUM",30 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_modulation_dst() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "Modulation Destinations";
    se1 = new SynthEnumElement ("Pitch",0 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O1 Pitch",1 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O1 FM",2 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O1 PW/Wav",3 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O2 Pitch",4 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O2 FM",5 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O2 PW/Wav",6 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O3 Pitch",7 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O3 FM",8 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement ("O3 PW",9 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("O1 Level",10 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("O1 Balance",11 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("O2 Level",12 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("O2 Balance",13 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("O3 Level",14 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("O3 Balance",15 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("RMod Leve",16 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("RMod Bal.",17 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("NoiseLevel",18 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("Noise Bal.",19 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F1 Cutoff",20 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F1 Reson.",21 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F1 FM",22 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F1 Drive",23 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F1 Pan",24 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F2 Cutoff",25 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F2 Reson.",26 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F2 FM",27 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F2 Drive",28 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("F2 Pan",29 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("Volume",30 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("LFO1Speed",31 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("LFO2Speed",32 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("LFO3Speed",33 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("FE Attack",34 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("FE Decay",35 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("FE Sustain",36 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("FE Release",37 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("AE Attack",38 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("AE Decay",39 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("AE Sustain",40 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("AE Release",41 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("E3 Attack",42 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("E3 Decay",43 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("E3 Sustain",44 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("E3 Release",45 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("E4 Attack",46 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("E4 Decay",47 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("E4 Sustain",48 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("E4 Release",49 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("M1 Amount",50 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("M2 Amount",51 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("M3 Amount",52 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement  ("M4 Amount",53 );
    monEnum->EnumValidation(se1);

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_modifier_ops() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "Modifier Operators";

    se1 = new SynthEnumElement("+",0 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("-",1 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("*",2 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("AND",3 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("OR",4 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("XOR",5 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Max.",6 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Min.",7 );
    monEnum->EnumValidation(se1);

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_fm_sources() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "FM Sources";

        se1 = new SynthEnumElement("off",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Osc 1",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Osc 2",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Osc 3",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Noise",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 1",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 2",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("LFO 3",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("FilterEnv",8 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("AmpEnv",9 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Env3",10 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Env4",11 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_fx1() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "FX1";

        se1 = new SynthEnumElement("Bypass",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Chorus",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Flanger",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Phaser",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Overdrive",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Triple FX",5 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_fx2() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "FX2";

        se1 = new SynthEnumElement("Bypass",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Chorus",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Flanger",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Phaser",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Overdrive",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Triple FX",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Delay",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Clk.Delay",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Reverb",8 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;


}
const SynthEnum * BlofeldTypesEnum::blotype_fx_driveCurve() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "FX DRIVE CURVES";

        se1 = new SynthEnumElement("Clipping",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Tube",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Hard",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Medium",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Soft",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Pickup 1",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Pickup 2",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Rectifier",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Square",8 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Binary",9 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement ("Overflow",10 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Sine Shaper",11 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}

const SynthEnum * BlofeldTypesEnum::blotype_InstruCat() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "INSTRUMENT CATEGORIES";

        se1 = new SynthEnumElement("Init",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Arp",1 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Atmosphere",2 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Bass",3 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Drum",4 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("FX",5 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Keys",6 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Lead",7 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Mono",8 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Pad",9 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Percussion",10 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Poly",11 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("Seq",12 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

}
const SynthEnum * BlofeldTypesEnum::blotype_switch() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "SWITCH";

        se1 = new SynthEnumElement("OFF",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("ON",1 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;


}
const SynthEnum * BlofeldTypesEnum::blotype_FilterRouting() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

        monEnum= new SynthEnum();
        monEnum->_nom= "FLTR_ROUTE";

        se1 = new SynthEnumElement("SERIAL",0 );
        monEnum->EnumValidation(se1);
        se1 = new SynthEnumElement("PARALLEL",1 );
        monEnum->EnumValidation(se1);

                monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_AroundZero() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "AROUND_ZERO";

    for(int i(0);i<128;i++){
        se1 = new SynthEnumElement(QString::number(i-64),i );
        monEnum->EnumValidation(se1);
    }
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_Keytrack() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "KEYTRACK";

    for(int i(0);i<128;i++){
        int num = floor(((float)(200)/64)*(i-64));
        QString s = QString::number(num) + " %" ;
        se1 = new SynthEnumElement(s,i);
        monEnum->EnumValidation(se1);
    }
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_Phase() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "LFO Phase";

    se1 = new SynthEnumElement("free",0);
        monEnum->EnumValidation(se1);

    for(int i(0);i<127;i++){
        int num = (((float)(i)*355)/126);
        QString s = QString::number(num) + " °" ;
        se1 = new SynthEnumElement(s,i+1);
            monEnum->EnumValidation(se1);
    }
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}


const SynthEnum * BlofeldTypesEnum::blotype_Chars() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "Chars";

    for(int i(32);i<128;i++){

        char c  = i;
        QString s("");
        s.append(c);
        se1 = new SynthEnumElement(s,i);
        monEnum->EnumValidation(se1);
    }
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_Standard() {
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "STANDARD";

    for(int i(0);i<128;i++){
        se1 = new SynthEnumElement(QString::number(i),i );
        monEnum->EnumValidation(se1);
    }
    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_arp_mode(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP MODE";

    se1 = new SynthEnumElement("off",0 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("on",1 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("One Shot",2 );
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Hold",3 );
    monEnum->EnumValidation(se1);

    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_arp_pattern(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP PATTERN";

    se1 = new SynthEnumElement("off",0 );
    monEnum->EnumValidation(se1);

    se1 = new SynthEnumElement("User",1 );
    monEnum->EnumValidation(se1);

    for(int i(0);i<16;i++){
        se1 = new SynthEnumElement("pattern " + QString::number(i),i+2 );
    }

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

    }
const SynthEnum * BlofeldTypesEnum::blotype_arp_clock(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP CLOCK";

    se1 = new SynthEnumElement("1/96",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/48",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/32 ",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16T",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/32.",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16 ",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8T",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16.",7); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8 ",8); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4T",9); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8.",10); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4 ",11); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2T",12); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4.",13); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2 ",14); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/1T",15); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2.",16); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1 bar",17); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1.5 bars",18); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("2 bars",19); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("2.5 bars",20); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("3 bars",21); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("3.5 bars",22); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("4 bars",23); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("5 bars",24); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("6 bars",25); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("7 bars",26); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("8 bars",27); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("9 bars",28); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("10 bars",29); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("12 bars",30); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("14 bars",31); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("16 bars",32); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("18 bars",33); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("20 bars",34); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("24 bars",35); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("28 bars",36); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("32 bars",37); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("36 bars",38); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("40 bars",39); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("48 bars",40); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("56 bars",41); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("64 bars",42); monEnum->EnumValidation(se1);

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_arp_length(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP LENGTH";

    se1 = new SynthEnumElement("1/96",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/48",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/32 ",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16T",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/32.",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16 ",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8T",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16.",7); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8 ",8); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4T",9); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8.",10); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4 ",11); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2T",12); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4.",13); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2 ",14); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/1T",15); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2.",16); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1 bar",17); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1.5 bars",18); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("2 bars",19); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("2.5 bars",20); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("3 bars",21); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("3.5 bars",22); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("4 bars",23); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("5 bars",24); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("6 bars",25); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("7 bars",26); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("8 bars",27); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("9 bars",28); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("10 bars",29); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("12 bars",30); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("14 bars",31); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("16 bars",32); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("18 bars",33); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("20 bars",34); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("24 bars",35); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("28 bars",36); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("32 bars",37); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("36 bars",38); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("40 bars",39); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("48 bars",40); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("56 bars",41); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("64 bars",42); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Legato",43); monEnum->EnumValidation(se1);

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_arp_octave(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP OCTAVE";
    for(int i(0);i<10;i++){
        se1 = new SynthEnumElement( QString::number(i+1),i );monEnum->EnumValidation(se1);
    }
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_arp_direction(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP DIRECTION";

    se1 = new SynthEnumElement("Up",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Down",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Alt Up",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Alt Down",3); monEnum->EnumValidation(se1);

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_arp_sort(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP SORT";

    se1 = new SynthEnumElement("as played",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("reversed",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Key Lo>Hi",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Key Hi>Lo",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Vel Lo>Hi",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Vel Hi>Lo",5); monEnum->EnumValidation(se1);

            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;

    }
const SynthEnum * BlofeldTypesEnum::blotype_arp_velocity(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP VELOC";

    se1 = new SynthEnumElement("Each Note",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("First Note",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Last Note",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("fix 32",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("fix 64",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("fix 100",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("fix 127",6); monEnum->EnumValidation(se1);
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}




const SynthEnum * BlofeldTypesEnum::blotype_arp_tempo(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP TEMPO";

    for(int i(0);i<128;i++){
        SynthEnumElement * se1;
        if(i<25){
            se1 = new SynthEnumElement(QString::number(floor(40+i*2)),i );
        }
        else if(i<100){
            se1 = new SynthEnumElement(QString::number(floor(90+i-25)),i );
        }
        else{
            se1 = new SynthEnumElement(QString::number(floor(165+(i-100)*5)),i );
        }
        monEnum->EnumValidation(se1);
    }


        monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_arp_ptn_step()
{
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP STEP";

    se1 = new SynthEnumElement("+",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("...",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("<",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1st",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("last",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("f+l",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("chord",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("?",7); monEnum->EnumValidation(se1);

    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}


const SynthEnum * BlofeldTypesEnum::blotype_arp_ptn_accent()
{
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP ACCENT";

    se1 = new SynthEnumElement("Silent",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("/4",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("/3",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("/2",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("*2",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("*3",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("*4",7); monEnum->EnumValidation(se1);

    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_arp_ptntiming(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP PATTERN TIMING";

    se1 = new SynthEnumElement("random",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("-3",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("-2",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("-1",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("0",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("+1",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("+2",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("+3",7); monEnum->EnumValidation(se1);

    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_arp_ptnlength(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "ARP PATTERN LENGTH";

    se1 = new SynthEnumElement("legato",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("-3",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("-2",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("-1",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("0",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("+1",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("+2",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("+3",7); monEnum->EnumValidation(se1);

    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_categories(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "CATEGORIES";

    se1 = new SynthEnumElement("off",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Init",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Arp",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Atmo",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Bass",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Drum",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("FX",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Keys",7); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Lead",8); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Mono",9); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Pad",10); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Perc",11); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Poly",12); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Seq",13); monEnum->EnumValidation(se1);
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_Channels(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "MIDI Channels";

    for(int i(0);i<16;i++){
        QString s = QString("Ch. %2d").arg(i+1);
        se1 = new SynthEnumElement(s,i);
        monEnum->EnumValidation(se1);
    }
    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}


const SynthEnum * BlofeldTypesEnum::blotype_bypass(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "bypass";
    se1 = new SynthEnumElement("bypass",0);
    monEnum->EnumValidation(se1);
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_polarity(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "polarity";
    se1 = new SynthEnumElement("-",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("+",1); monEnum->EnumValidation(se1);
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_dl_length(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "fx delay Length";
    se1 = new SynthEnumElement("1/96",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/48",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/32 ",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16T",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/32.",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16 ",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8T",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/16.",7); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8 ",8); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4T",9); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/8.",10); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4 ",11); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2T",12); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/4.",13); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2 ",14); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/1T",15); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1/2.",16); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1 bar",17); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("1.5 bars",18); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("2 bars",19); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("2.5 bars",20); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("3 bars",21); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("3.5 bars",22); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("4 bars",23); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("5 bars",24); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("6 bars",25); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("7 bars",26); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("8 bars",27); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("9 bars",28); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("10 bars",29); monEnum->EnumValidation(se1);
            monEnum->sort(); const SynthEnum * e(monEnum);
        return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_bank(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Banks";
    se1 = new SynthEnumElement("A",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("B",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("C",2); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("D",3); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("E",4); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("F",5); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("G",6); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("H",7); monEnum->EnumValidation(se1);
    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}


const SynthEnum * BlofeldTypesEnum::blotype_MessageType(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "message type";
    se1 = new SynthEnumElement("Request",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Dump",1); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Parameter Change",2); monEnum->EnumValidation(se1);
    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_MessageStructureType(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "message structure type";
    se1 = new SynthEnumElement("SND",0); monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("GLB",4); monEnum->EnumValidation(se1);
    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}


const SynthEnum * BlofeldTypesEnum::blotype_multi_transpose(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "multi transposistion";

    for(int i(-48);i<49;i++){
        se1 = new SynthEnumElement(QString::number(i),i+64 );
        monEnum->EnumValidation(se1);
    }
    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_multi_channel(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "multi channel";

    se1 = new SynthEnumElement("global",0 );
    monEnum->EnumValidation(se1);

    se1 = new SynthEnumElement("omni",1 );
    monEnum->EnumValidation(se1);

    for(int i(0);i<16;i++){
        se1 = new SynthEnumElement(QString::number(i+1),i+2 );
        monEnum->EnumValidation(se1);
    }
    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_multi_note(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "multi Note";

    for(int i(0);i<128;i++){
        se1 = new SynthEnumElement(MidiUtility::getNoteFullName(i),i);
        monEnum->EnumValidation(se1);
    }
    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}


const SynthEnum * BlofeldTypesEnum::blotype_glob_popup(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Popup Time";


    double max = 15.5;
    double min = 0.1;
    double step = (max-min)/127;

    for(int i(0);i<128;i++)
    {
        se1 = new SynthEnumElement(QString::number(min+step*i),i);
        monEnum->EnumValidation(se1);
    }
    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_glob_mastune()
{
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Master Tune";

    for(int i(0);i<21;i++)
    {
        se1 = new SynthEnumElement(QString::number(430+i),i+54);
        monEnum->EnumValidation(se1);
    }
    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_glob_sendCtrl(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Master Send Ctrl";

    se1 = new SynthEnumElement("off",0);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Ctrl",1);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Sysex",2);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Ctrl+Sysex",3);
    monEnum->EnumValidation(se1);

    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_glob_curve(){

    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Velocity Curve";

    se1 = new SynthEnumElement("linear",0);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Square",1);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Cubic",2);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("exponential",3);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("root",4);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("fix32",5);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("fix64",6);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("fix100",7);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("fix127",8);
    monEnum->EnumValidation(se1);

    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_glob_ctrlnum(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Controller WXYZ";

    for(int i(0);i<121;i++)
    {
        se1 = new SynthEnumElement(QString::number(i),i);
        monEnum->EnumValidation(se1);
    }
    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}
const SynthEnum * BlofeldTypesEnum::blotype_glob_freebutton(){

    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Free Button";

    se1 = new SynthEnumElement("off",0);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Sustain",1);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Sust.toggle",2);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Control W",3);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Control X",4);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Control Y",5);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("Control Z",6);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("C.W toggle",7);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("C.X toggle",8);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("C.Y toggle",9);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("C.Z toggle",10);
    monEnum->EnumValidation(se1);
    se1 = new SynthEnumElement("mute",11);
    monEnum->EnumValidation(se1);

    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_glob_centered(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Centered Standard";

    for(int i(0);i<128;i++)
    {
        QString s = QString("%1").arg(i-64);
        se1 = new SynthEnumElement(s,i);
        monEnum->EnumValidation(se1);
    }
    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_glob_pan()
{
    SynthEnum * monEnum ;
    SynthEnumElement * se1;
    monEnum= new SynthEnum();
    monEnum->_nom= "Pan";

    for(int i(0);i<63;i++)
    {
        QString s = QString("Left %1").arg(i-64);
        se1 = new SynthEnumElement(s,i);
        monEnum->EnumValidation(se1);
    }
    se1 = new SynthEnumElement("CENTER",63);
    monEnum->EnumValidation(se1);

    for(int i(0);i<64;i++)
    {
        QString s = QString("Right %1").arg(i);
        se1 = new SynthEnumElement(s,i+64);
        monEnum->EnumValidation(se1);
    }

    monEnum->sort();
    const SynthEnum * e(monEnum);
    return e;
}

const SynthEnum * BlofeldTypesEnum::blotype_glob_vol(){
    SynthEnum * monEnum ;
    SynthEnumElement * se1;

    monEnum= new SynthEnum();
    monEnum->_nom= "VOL. NOT NULL";

    for(int i(0);i<127;i++){
        se1 = new SynthEnumElement(QString::number(i+1),i );
        monEnum->EnumValidation(se1);
    }
    monEnum->sort(); const SynthEnum * e(monEnum);
    return e;
}

