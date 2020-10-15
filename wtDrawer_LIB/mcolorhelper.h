#ifndef MCOLORHELPER_H
#define MCOLORHELPER_H

#include <QColor>

class MColorHelper
{
protected:
    QColor
    _clr_srt,
    _clr_1_4_end,
    _clr_3_4_end,
    _clr_2_4_end,
    _clr_White,
    _clr_Top,
    _clr_GrayLine,
    _clr_Black
    ;
public:
    MColorHelper();

    QColor getColorPhase(double vph);
    double getPhaseBrightness(double phase);
    int scaleValue(int fromv, int tov, double ratio);
    QColor scaleColor(QColor c1, QColor c2, double ratio);

};

#endif // MCOLORHELPER_H
