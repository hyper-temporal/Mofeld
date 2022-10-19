#ifndef DEFS_H
#define DEFS_H
#include <QStandardItemModel>

//Structure de persistance dans le synthe
#define _BLOFELD_BANKNUM 8
#define _BLOFELD_PGMNUM 128
#define _BLOFELD_WT_NUM 38
#define _BLOFELD_WT_USEROFFSET 80
//l'enumeration des wavetable est dynamique: on a des wavetable en lecture seule et d'autres editable
//
/* TYPE d'objets gui */
#define BLO_GUI_COMBO 0
#define BLO_GUI_HSLIDER 1
#define BLO_GUI_VSLIDER   2
#define BLO_GUI_SWITCH  3

const QColor color_chk(0xe7,0x01,0x01,255); //rouge
const QColor color_int(0xad,0xc9,0xec,255);     //jaune
const QColor color_intfix(0xe0,0xde,0xef,255);     //jaune
const QColor color_cst(0x00,0x00,0x00,255);         //gris clair
const QColor color_string(0xee,0x67,0xfa,255);      // rose pale
const QColor color_Channel(0x67,0xe8,0xef,255);     // blue pale
const QColor color_Bank(0xef,0xc0,0x67,255);        // orange pale
const QColor color_Prog(0x8b,0xef,0x67,255);        // vert clair
const QColor color_RANGE(0xff,0x8f,0x8f,255);        // vert clair
const QColor color_ENUM(0x8b,0xef,0x67,255);        // vert clair

/*
Allocation and Unisono Modes
*****************************************************************************
*/

#define		UNISONO_0_POLY		0x00
#define		UNISONO_1_POLY        	0x10
#define		UNISONO_3_POLY          0x20
#define		UNISONO_4_POLY          0x30
#define		UNISONO_5_POLY          0x40
#define		UNISONO_6_POLY          0x50
#define		UNISONO_0_MONO		0x01
#define		UNISONO_1_MONO        	0x11
#define		UNISONO_3_MONO          0x21
#define		UNISONO_4_MONO          0x31
#define		UNISONO_5_MONO          0x41
#define		UNISONO_6_MONO          0x51



/*
Glide Modes
*****************************************************************************
*/
#define		GLIDEMODE_Portamento	0
#define		GLIDEMODE_fingeredP     1
#define		GLIDEMODE_Glissando     2
#define		GLIDEMODE_fingeredG     3
/*
TUNING
*****************************************************************************
*/
#define		KEYTRACK_196 	0x7f
#define		KEYTRACK_150 	0x70
#define		KEYTRACK_100 	0x60
#define		KEYTRACK_50 	0x50
#define		KEYTRACK_25 	0x48
#define		KEYTRACK_0 	0x40
#define		KEYTRACK_200m 	0x0
#define		KEYTRACK_150m 	0x10
#define		KEYTRACK_100m 	0x20
#define		KEYTRACK_50m 	0x30
#define		KEYTRACK_25m 	0x38

#define	PITCHMODAMOUNT_0 	0x40
#define	BENDRANGE_0 		0x40
#define	SEMITONE_0 		0x40
#define	DETUNE_0 		0x40
#define	BALANCE_CENTER 		0x40

#define	OCTAVE_128 	0x10
#define	OCTAVE_64 	0x1c
#define	OCTAVE_32 	0x28
#define	OCTAVE_16 	0x34
#define	OCTAVE_8 	0x40
#define	OCTAVE_4 	0x4c
#define	OCTAVE_2 	0x58
#define	OCTAVE_1 	0x64
#define	OCTAVE_12 	0x70

/*
SHAPING
*****************************************************************************
*/
#define	SHAPE_OFF 		0x00
#define	SHAPE_SQUARE 		0x01
#define	SHAPE_RAMP 		0x02
#define	SHAPE_TRIANGLE 		0x03
#define	SHAPE_SINE 		0x04
#define	SHAPE_MAX1 		0x48
#define	SHAPE_MIN2 		0x56
#define	SHAPE_MAX2 		0x79

#define	LIMITWT_ON 		0x00
#define	LIMITWT_OFF 		0x01



/*
Filter Types
*****************************************************************************
*/

#define		FLTRCUTOFF_0          41
#define		FLTRRESO_HIGH          0x2f
#define		ENVAMOUNT_OFF          0x40

#define		FLTRTYPE_Bypass		0
#define		FLTRTYPE_LP24dB         1
#define		FLTRTYPE_LP12dB         2
#define		FLTRTYPE_BP24dB         3
#define		FLTRTYPE_BP12dB         4
#define		FLTRTYPE_HP24dB         5
#define		FLTRTYPE_HP12dB         6
#define		FLTRTYPE_Notch24dB       7
#define		FLTRTYPE_Notch12dB       8
#define		FLTRTYPE_CombP           9
#define		FLTRTYPE_CombN           10
#define		FLTRTYPE_PPGLP          11

#define		FLTRROUTE_SERIAL          2
#define		FLTRROUTE_PARALLEL          1
/*
Envelope Modes and Triggers
*****************************************************************************
*/

#define		ENVTYPE_NORMAL_ADSR		0x00
#define		ENVTYPE_NORMAL_ADS1DS2R    	0x01
#define		ENVTYPE_NORMAL_OneShot    	0x02
#define		ENVTYPE_NORMAL_LoopS1S2   	0x03
#define		ENVTYPE_NORMAL_LoopAll    	0x04
#define		ENVTYPE_SINGLE_ADSR		0x20
#define		ENVTYPE_SINGLE_ADS1DS2R    	0x21
#define		ENVTYPE_SINGLE_OneShot    	0x22
#define		ENVTYPE_SINGLE_LoopS1S2   	0x23
#define		ENVTYPE_SINGLE_LoopAll    	0x24

/*
LFO Shapes
*****************************************************************************

*/
#define		LFOSHAPE_Sine        0
#define		LFOSHAPE_Triangle    1
#define		LFOSHAPE_Square      2
#define		LFOSHAPE_Saw          3
#define		LFOSHAPE_Random       4
#define		LFOSHAPE_SH          5
#define		LFOFADE_0         0x40
#define		LFOCLOCK_OFF         0x40
#define		LFOCLOCK_ON         0x40
#define		LFOSYNC_OFF         0x40
#define		LFOSYNC_ON         0x40
#define		LFOPHASE_FREE         0x00
#define		LFOPHASE_0         0x01
#define		LFOPHASE_30         0x0c
#define		LFOPHASE_45         0x11
#define		LFOPHASE_90         0x21
#define		LFOPHASE_180         0x41
#define		LFOPHASE_270         0x61


/*

FM Sources
*****************************************************************************
*/
#define		FMSOURCE_OFF		0
#define		FMSOURCE_Osc1           1
#define		FMSOURCE_Osc2           2
#define		FMSOURCE_Osc3           3
#define		FMSOURCE_Noise          4
#define		FMSOURCE_LFO1           5
#define		FMSOURCE_LFO2           6
#define		FMSOURCE_LFO3           7
#define		FMSOURCE_FilterEnv      8
#define		FMSOURCE_AmpEnv         9
#define		FMSOURCE_Env3           10
#define		FMSOURCE_Env4           11

/*
Modulation Sources
*****************************************************************************
*/
#define		MODSOURCE_off		0
#define		MODSOURCE_LFO1           1
#define		MODSOURCE_LFO1MW         2
#define		MODSOURCE_LFO2           3
#define		MODSOURCE_LFO2Press      4
#define		MODSOURCE_LFO3           5
#define		MODSOURCE_FilterEnv       6
#define		MODSOURCE_AmpEnv          7
#define		MODSOURCE_Env3            8
#define		MODSOURCE_Env4            9
#define		MODSOURCE_Keytrack        10
#define		MODSOURCE_Velocity        11
#define		MODSOURCE_RelVelo       12
#define		MODSOURCE_Pressure        13
#define		MODSOURCE_PolyPress      14
#define		MODSOURCE_PitchBend      15
#define		MODSOURCE_ModWheel       16
#define		MODSOURCE_Sustain         17
#define		MODSOURCE_FootCtrl       18
#define		MODSOURCE_BreathCtrl      19
#define		MODSOURCE_ControlW       20
#define		MODSOURCE_ControlX       21
#define		MODSOURCE_ControlY       22
#define		MODSOURCE_ControlZ       23
#define		MODSOURCE_UnisonoV      24
#define		MODSOURCE_Modifier1      25
#define		MODSOURCE_Modifier2      26
#define		MODSOURCE_Modifier3      27
#define		MODSOURCE_Modifier4      28
#define		MODSOURCE_minimum         29
#define		MODSOURCE_MAXIMUM         30


/*
Modulation Destinations
*****************************************************************************
*/
#define		MODDEST_Pitch			0
#define		MODDEST_O1_Pitch        1
#define		MODDEST_O1_FM           2
#define		MODDEST_O1_PWWave      3
#define		MODDEST_O2_Pitch        4
#define		MODDEST_O2_FM           5
#define		MODDEST_O2_PWWave      6
#define		MODDEST_O3_Pitch        7
#define		MODDEST_O3_FM           8
#define		MODDEST_O3_PW           9
#define		MODDEST_O1_Level        10
#define		MODDEST_O1_Balance      11
#define		MODDEST_O2_Level        12
#define		MODDEST_O2_Balance      13
#define		MODDEST_O3_Level        14
#define		MODDEST_O3_Balance      15
#define		MODDEST_RMod_Level      16
#define		MODDEST_RMod_Bal       17
#define		MODDEST_Noise_Level      18
#define		MODDEST_Noise_Bal      19
#define		MODDEST_F1_Cutoff       20
#define		MODDEST_F1_Reson       21
#define		MODDEST_F1_FM           22
#define		MODDEST_F1_Drive        23
#define		MODDEST_F1_Pan          24
#define		MODDEST_F2_Cutoff       25
#define		MODDEST_F2_Reson       26
#define		MODDEST_F2_FM           27
#define		MODDEST_F2_Drive        28
#define		MODDEST_F2_Pan          29
#define		MODDEST_Volume          30
#define		MODDEST_LFO1Speed       31
#define		MODDEST_LFO2Speed       32
#define		MODDEST_LFO3Speed       33
#define		MODDEST_FE_Attack       34
#define		MODDEST_FE_Decay        35
#define		MODDEST_FE_Sustain      36
#define		MODDEST_FE_Release      37
#define		MODDEST_AE_Attack       38
#define		MODDEST_AE_Decay        39
#define		MODDEST_AE_Sustain      40
#define		MODDEST_AE_Release      41
#define		MODDEST_E3_Attack       42
#define		MODDEST_E3_Decay        43
#define		MODDEST_E3_Sustain      44
#define		MODDEST_E3_Release      45
#define		MODDEST_E4_Attack       46
#define		MODDEST_E4_Decay        47
#define		MODDEST_E4_Sustain      48
#define		MODDEST_E4_Release      49
#define		MODDEST_M1_Amount       50
#define		MODDEST_M2_Amount       51
#define		MODDEST_M3_Amount       52
#define		MODDEST_M4_Amount       53

/*
Modifier Operators
*****************************************************************************
*/
#define		MODIFIEROPP_ADD			0
#define		MODIFIEROPP_REM           1
#define		MODIFIEROPP_MUL           2
#define		MODIFIEROPP_AND         3
#define		MODIFIEROPP_OR          4
#define		MODIFIEROPP_XOR         5
#define		MODIFIEROPP_MAX         6
#define		MODIFIEROPP_MIN         7

#define		MODIFIERCONSTANTEVALUE_0         0x40



/*
Arpeggiator Clocks
*****************************************************************************
*/
#define		ARP_CLOCK_196	0
#define		ARP_CLOCK_64    42


/*
Arpeggiator Sort Orders
*****************************************************************************
*/
#define		ARP_SORT_asplayed	0
#define		ARP_SORT_reversed    1
#define		ARP_SORT_KeyLoHi   2
#define		ARP_SORT_KeyHiLo   3
#define		ARP_SORT_VelLoHi   4
#define		ARP_SORT_VelHiLo   5




/*
Effect Types
*****************************************************************************
*/
#define		FXTYPE_Bypass             		0
#define		FXTYPE_Chorus    		1
#define		FXTYPE_Flanger   		2
#define		FXTYPE_Phaser   		3
#define		FXTYPE_Overdrive		4
#define		FXTYPE_TripleFX 		5
#define		FXTYPE_Delay    		6
#define		FXTYPE_ClkDelay 		7
#define		FXTYPE_Reverb    		8

/*
Drive Curves
*****************************************************************************
*/
#define		FX_DRIVECURVE_Clipping		0
#define		FX_DRIVECURVE_Tube            1
#define		FX_DRIVECURVE_Hard            2
#define		FX_DRIVECURVE_Medium          3
#define		FX_DRIVECURVE_Soft            4
#define		FX_DRIVECURVE_Pickup1        5
#define		FX_DRIVECURVE_Pickup2        6
#define		FX_DRIVECURVE_Rectifier       7
#define		FX_DRIVECURVE_Square          8
#define		FX_DRIVECURVE_Binary          9
#define		FX_DRIVECURVE_Overflow        10
#define		FX_DRIVECURVE_SineShaper     11
#define		FX_DRIVECURVE_Osc1Mod       12


#define METHOD_RANGE_RESTRICT   0
#define METHOD_RANGE_EXTEND     1
#define METHOD_RANGE_KEEPMINS   2
#define METHOD_RANGE_KEEPMAX    3


#define METHOD_RESTRICT 0
#define METHOD_EXTEND   1
#define METHOD_FIX      2

namespace OperationProps{
    enum OperationLayer { prop_channel=0, prop_Instru=1, instruOnly=2 };
    enum Meth_flexibility { meth_Replace=0, meth_Force=1, meth_Weak=2};
}


#endif //DEFS_H

