#ifndef BLOFENUMS_H
#define BLOFENUMS_H


#include "synthenum.h"
#include <QFile>
#include <QMessageBox>

#include "midiutility.h"

enum  class VAccessor
{
    accessnone  = 0,
    accessMulti  = 1,
    accessInstrument  = 2,
    accessGlobal  = 3,
};
#define BLOT_STANDARD           (0)
#define BLOT_OSC_SHAPES12        (1)
#define BLOT_OSC_SHAPES3         (2)
#define BLOT_OSC_PWM_SOURCE      (3)
#define BLOT_OSC_OCTAVE          (4)
#define BLOT_OSC_SEMITONE        (5)
#define BLOT_OSC_BENDRANGE       (6)
#define BLOT_POLYPHONY           (7)
#define BLOT_GLIDEMODE           (8)
#define BLOT_FILTER_TYPE         (9)
#define BLOT_FILTER_DRIVE        (10)
#define BLOT_LFO_SHAPES          (11)
#define BLOT_ENV_MODES           (12)
#define BLOT_ENV_TRIGGER         (13)
#define BLOT_MODULATION_SRC      (14)
#define BLOT_MODULATION_DST      (15)
#define BLOT_MODIFIER_OPS        (16)
#define BLOT_FM_SOURCES          (17)
#define BLOT_FX1                 (18)
#define BLOT_FX2                 (19)
#define BLOT_FX_DRIVESHAPE       (20)
#define BLOT_CATEGORIES          (21)
#define BLOT_SWITCH              (22)
#define BLOT_ROUTING             (23)
#define BLOT_AROUNDZ             (24)
#define BLOT_KEYTRACK            (25)
#define BLOT_PHASE               (26)
#define BLOT_CHARZ               (27)
#define BLOT_ARPMODE        (28)
#define BLOT_ARPCLOCK       (29)
#define BLOT_TEMPO       (30)
#define BLOT_ARPPATTERN     (31)
#define BLOT_ARPDIRECTION   (32)
#define BLOT_ARPOCTAVE      (33)
#define BLOT_ARPLENGTH      (34)
#define BLOT_ARPSORT        (35)
#define BLOT_ARPVELOCITY    (36)
#define BLOT_ARP_PTNSTEP    (37)
#define BLOT_ARP_PTNACCENT  (38)
#define BLOT_ARP_PTNTIME    (39)
#define BLOT_ARP_PTNLENGTH  (40)
#define BLOT_CHANNEL        (41)
#define BLOT_BYPASS         (42)
#define BLOT_POLARITY       (43)
#define BLOT_DL_LENGTH      (44)

#define BLOT_BANK        (45)

#define BLOT_MULTI_TRANSPOSE        (46)
#define BLOT_MULTI_CHANNEL        (47)
#define BLOT_MULTI_NOTE        (48)
#define BLOT_GLOB_POPUP        (49)
#define BLOT_GLOB_MASTUNE        (50)
#define BLOT_GLOB_TRANSPOSE        (BLOT_OSC_SEMITONE)
#define BLOT_GLOB_SEND_CTRL        (51)
#define BLOT_GLOB_CURVE        (52)
#define BLOT_GLOB_CTRL        (53)
#define BLOT_GLOB_FREEBUTTON        (54)

#define BLOT_CENTERED        (55)
#define BLOT_PAN        (56)
#define BLOT_VOLFROM1        (57)


class BlofeldTypesEnum
{
    QVector<const SynthEnum*> LesEnums;
    void AddEnum(const SynthEnum *);
    void ReplaceEnum( const SynthEnum *);
    void DeleteEnum(int i);
    void AddElement(SynthEnumElement e);
    void RemoveElement(int i);
    bool LoadEnumsXML(QString fileName);

public:

    static BlofeldTypesEnum& getInstance()
    {
     static BlofeldTypesEnum    instance; // Guaranteed to be destroyed.
                           // Instantiated on first use.
     return instance;
    }

    const SynthEnum* GetEnum(int i)const ;
    const SynthEnum* GetEnum(QString nom)const;
    int getValidValue(int input, int type)const;

private:

private:
    BlofeldTypesEnum();
    BlofeldTypesEnum(BlofeldTypesEnum const&);// Don't Implement
    void operator=(BlofeldTypesEnum const&);


/*0*/     const SynthEnum *  blotype_Standard();
/*1*/     const SynthEnum *  blotype_osc_shapes12() ;
/*2*/     const SynthEnum *  blotype_osc_UserShapes();
/*3*/     const SynthEnum *  blotype_osc_shapes3() ;
/*4*/     const SynthEnum *  blotype_osc_pwm_source() ;
/*5*/     const SynthEnum *  blotype_osc_octave() ;
/*6*/     const SynthEnum *  blotype_osc_semitone() ;
/*7*/     const SynthEnum *  blotype_osc_bendrange() ;
/*8*/     const SynthEnum *  blotype_polyphony() ;
/*9*/     const SynthEnum *  blotype_glidemode() ;
/*10*/    const SynthEnum *  blotype_filter_type() ;
/*11*/    const SynthEnum *  blotype_filter_drive() ;
/*12*/    const SynthEnum *  blotype_lfo_shapes() ;
/*13*/    const SynthEnum *  blotype_env_modes() ;
/*14*/    const SynthEnum *  blotype_env_trigger() ;
/*15*/    const SynthEnum *  blotype_modulation_src() ;
/*16*/    const SynthEnum *  blotype_modulation_dst() ;
/*17*/    const SynthEnum *  blotype_modifier_ops() ;
/*18*/    const SynthEnum *  blotype_fm_sources() ;
/*19*/    const SynthEnum *  blotype_fx1() ;
/*20*/    const SynthEnum *  blotype_fx2() ;
/*21*/    const SynthEnum *  blotype_fx_driveCurve() ;
/*22*/    const SynthEnum *  blotype_InstruCat();
/*23*/    const SynthEnum *  blotype_switch() ;
/*24*/    const SynthEnum *  blotype_FilterRouting() ;
/*25*/    const SynthEnum *  blotype_AroundZero();
/*26*/    const SynthEnum *  blotype_Keytrack();
/*27*/    const SynthEnum *  blotype_Phase();
/*28*/    const SynthEnum *  blotype_Chars();
/*29*/    const SynthEnum *  blotype_arp_mode();
/*30*/    const SynthEnum *  blotype_arp_pattern();
/*31*/    const SynthEnum *  blotype_arp_clock();
/*32*/    const SynthEnum *  blotype_arp_length();
/*33*/    const SynthEnum *  blotype_arp_octave();
/*34*/    const SynthEnum *  blotype_arp_direction();
/*35*/    const SynthEnum *  blotype_arp_sort();
/*36*/    const SynthEnum *  blotype_arp_velocity();
/*37*/    const SynthEnum *  blotype_arp_tempo();
/*38*/    const SynthEnum *  blotype_arp_ptn_step();
/*39*/    const SynthEnum *  blotype_arp_ptn_accent();
/*40*/    const SynthEnum *  blotype_arp_ptntiming();
/*41*/    const SynthEnum *  blotype_arp_ptnlength();
/*42*/    const SynthEnum *  blotype_categories();
/*43*/    const SynthEnum *  blotype_Channels();
/*44*/    const SynthEnum *  blotype_bypass();
/*45*/    const SynthEnum *  blotype_polarity();
/*46*/    const SynthEnum *  blotype_dl_length();
/*47*/    const SynthEnum *  blotype_bank();
/*48*/    const SynthEnum * blotype_multi_transpose();
/*49*/    const SynthEnum * blotype_multi_channel();
/*50*/    const SynthEnum * blotype_multi_note();
/*51*/    const SynthEnum * blotype_glob_popup();
/*52*/    const SynthEnum * blotype_glob_mastune();
/*53*/    const SynthEnum * blotype_glob_sendCtrl();
/*54*/    const SynthEnum * blotype_glob_curve();
/*55*/    const SynthEnum * blotype_glob_ctrlnum();
/*56*/    const SynthEnum * blotype_glob_freebutton();
/*57*/    const SynthEnum * blotype_glob_centered();
/*58*/    const SynthEnum * blotype_glob_pan();
/*59*/    const SynthEnum * blotype_glob_vol();

/*48*/    const SynthEnum * blotype_MessageType();
/*49*/    const SynthEnum * blotype_MessageStructureType();


};



#endif // BLOFENUMS_H





