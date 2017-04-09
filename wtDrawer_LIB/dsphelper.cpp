#include "dsphelper.h"

DSPHelper::DSPHelper(unsigned int dim)
    :IRealSignal(dim)
{
    _sinusPrecision = 4096;
    sinus();
}

double DSPHelper::sin_x( double x)
{
    double	resultat =x;
    while(resultat< 0){resultat=resultat+(2*M_PI);}
    while(resultat>= 2*M_PI){resultat=resultat-(2*M_PI);}
    resultat = _sinus[(unsigned int)(resultat*_sinusPrecision/(2*M_PI))];
    return resultat;
}

double DSPHelper::cos_x( double x)
{
    double resultat= M_PI/2 +x;
    resultat = sin_x(resultat);
    return resultat;
}

int _sinusPrecision;
void DSPHelper::sinus()
{
    _sinus.resize(_sinusPrecision);

    for (int cnt=0; cnt<_sinusPrecision; cnt++)
    {
        _sinus[cnt] = sin(2*M_PI*cnt/_sinusPrecision);
    }
}

QVector<double> DSPHelper::getTriangle()
{
    QVector<double> ret(_size);

    int cnt;
    for ( cnt=0 ; cnt< _size/4 ; cnt++)
    {
        ret[cnt] = (double)(4*cnt)/_size;	//1er quart de periode
    }

    for ( cnt=_size/4	; cnt< 3*_size/4 ; cnt++)
    {
        ret[cnt]= 1-(double)(4*cnt-_size)/_size;
    }

    for ( cnt=3*_size/4 ; cnt< _size ; cnt++)
    {
        ret[cnt] = -1 +(double)(4*cnt-3*_size)/_size;		//faire une rampe de -1 à 1
    }
    return ret;

}

QVector<double> DSPHelper::getRamp()
{
    QVector<double> ret(_size);

    for (int cnt=0; cnt<_size; cnt++)
    {
        ret[cnt] = -1.0 +(double)(2*cnt)/_size;		//faire une rampe de -1 à 1
    }
    return ret;
}

QVector<double> DSPHelper::getRandom()
{
    QVector<double> ret(_size);
    for (int cnt=0; cnt<_size;cnt++)
    {
        ret[cnt]=4*(qrand()/(double)0xFFFF)-1;
    }
    return ret;
}

QVector<double> DSPHelper::getSinus()
{
    QVector<double> ret;
    for (int cnt=0; cnt<_size;cnt++)
    {
        int s = _sinusPrecision*(double) cnt/_size;
        if(s<_sinusPrecision){
            ret.append(_sinus[s]);
        }else{
            ret.append(_sinus[_sinusPrecision-1]);
        }
    }
    return ret;
}

QVector<double> DSPHelper::getSquare(int percent)
{
    QVector<double> ret(_size);

    int snum = (_size * percent) /100;
    for (int cnt=0; cnt<_size; cnt++)
    {

        if (cnt<snum)				//
        {							//generateur PWM
            ret[cnt] 	= 1;	// état haut
        }							//
        else			//
        {							//
            ret[cnt] 	= -1;	//état bas
        }
    }
    return ret;
}

void DSPHelper::fillSignal(QVector<double> srce, QVector<double> *dest, int periode){

    if(     srce.count() != _size
        ||  srce.count()!= dest->count()
        ||  periode<0 )
    {
        throw("mauvais parametrage");
    }

    int scaledSample=0;
    for(int cnt=0; cnt<_size; cnt++)
    {
        (*dest)[cnt]=srce[scaledSample];
        scaledSample = (scaledSample+periode)%_size;
    }
}
