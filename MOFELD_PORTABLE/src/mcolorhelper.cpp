#include "mcolorhelper.h"

MColorHelper::MColorHelper()
{
    _clr_srt= QColor(220,80,180);
    _clr_1_4_end= QColor(100,130,170);
    _clr_3_4_end= QColor(170,150,120);
    _clr_2_4_end= QColor(220,190,90);
    _clr_White= QColor(255,255,220);
    _clr_Top= QColor(120,120,120);
    _clr_GrayLine=QColor(18,160,250);
    _clr_Black=QColor(0,0,0);
}



int MColorHelper::scaleValue(int fromv, int tov, double ratio)
{
    int v =  tov - fromv ;
    if(v<0.0 ){ v = -v;}
    if(tov>fromv)
    {
        return (int)(fromv + v*ratio);
    }else{
        return (int)(fromv - v*ratio);
    }
}


QColor MColorHelper::scaleColor(QColor c1, QColor c2, double ratio)
{
    int RedComp, GreenComp,BlueComp;

    RedComp = scaleValue(c1.red(),c2.red(),ratio);
    GreenComp = scaleValue(c1.green(),c2.green(),ratio);
    BlueComp = scaleValue(c1.blue(),c2.blue(),ratio);
//    return QColor(RedComp&0xFF,GreenComp&0xFF,BlueComp&0xFF);
    return QColor(RedComp,GreenComp,BlueComp);
}

QColor  MColorHelper::getColorPhase(double phase){

    QColor col1,col2;
    double rescale = phase;
    double rescaleCol,bright;

    if(rescale<1.0/4)
    {
       col1 = _clr_srt,
       col2 = _clr_1_4_end;
       rescaleCol=rescale;
       bright = 1.0-4*rescaleCol;
    }
    else if(rescale<2.0/4)
    {
        col1 = _clr_1_4_end,
        col2 = _clr_2_4_end;
        rescaleCol=rescale-1.0/4;
        bright = 4*rescaleCol;
    }
    else if(rescale<3.0/4)
    {
        col1 = _clr_2_4_end,
        col2 = _clr_3_4_end;
        rescaleCol=rescale-2.0/4;
        bright = 1.0-4*rescaleCol;
    }
    else
    {
        col1 = _clr_3_4_end,
        col2 = _clr_srt;
        rescaleCol=rescale-3.0/4;
        bright = 4*rescaleCol;
    }
    if (rescaleCol<0.0)rescaleCol=0.0;
    else if (rescaleCol>1.0/4)rescaleCol=1.0/4;
    if(bright<0.0)bright=0.0;
    if(bright>1.0)bright=1.0;
    QColor cc =  scaleColor(col1,col2,4*rescaleCol);
    return cc;
}


double  MColorHelper::getPhaseBrightness(double vp){

    double rescaleCol,bright;

    if(vp<1.0/4)
    {
       rescaleCol=vp;
       bright = 1.0-4*rescaleCol;
    }
    else if(vp<2.0/4)
    {
        rescaleCol=vp-1.0/4;
        bright = 4*rescaleCol;
    }
    else if(vp<3.0/4)
    {
        rescaleCol=vp-2.0/4;
        bright = 1.0-4*rescaleCol;
    }
    else
    {
        rescaleCol=vp-3.0/4;
        bright = 4*rescaleCol;
    }
    if (rescaleCol<0.0)rescaleCol=0.0;
    else if (rescaleCol>1.0/4)rescaleCol=1.0/4;
    if(bright<0.0)bright=0.0;
    if(bright>1.0)bright=1.0;
    return 1.0-bright;
}
