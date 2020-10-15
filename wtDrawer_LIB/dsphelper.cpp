#include "dsphelper.h"

#define _USE_MATH_DEFINES
#include <math.h>

DSPHelper::DSPHelper(unsigned int dim)
    :IRealSignal(dim)
{
    _lanczosCoreSize = 2;
    _sinusPrecision = 4096;
    sinus();
}
double DSPHelper::sin_x( double x) const
{
    double	resultat =x;
    while(resultat< 0){resultat+=(2*M_PI);}
    while(resultat>= 2*M_PI){resultat-=(2*M_PI);}
    int pos = (unsigned int)(resultat*_sinusPrecision/(2*M_PI));
    return _sinus[pos];

//    if(resultat<0.000001 && resultat>-0.000001){
//        resultat=0.0;
//    }
//    return resultat;
}

double DSPHelper::cos_x( double x) const
{
    double resultat= M_PI/2 +x;
    resultat = sin_x(resultat);
    return resultat;
}

void DSPHelper::sinus()
{
    _sinus.resize(_sinusPrecision);

    for (int cnt=0; cnt<_sinusPrecision; cnt++)
    {
        _sinus[cnt] = sin(2*M_PI*cnt/_sinusPrecision);
    }
//    _sinus[_sinusPrecision/2]=1.0;
//    _sinus[_sinusPrecision-1]=0.0;
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
        ret[cnt]= -1.0 + 2.0 * (double)qrand()/INT_MAX;
    }
    return ret;
}

QVector<double> DSPHelper::getSinus( )
{
    QVector<double> ret(_size);

    for (int cnt=0; cnt<_size; cnt++)
    {
        ret[cnt] = sin_x(2*M_PI*cnt/_size);
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

//il sqgit de generer une courbe auùon scqlerq ensuite pour chqaue point
QVector<double> DSPHelper::getLanczosCore(int sampleCount)const{
    QVector<double> core(sampleCount);
    double prop = (double)2*_lanczosCoreSize/sampleCount;

    double res=0.0;

    for(int samplenum(0);samplenum<sampleCount;samplenum++)
    {

        if(samplenum*2== sampleCount){
            res=1.0;
        }else if(samplenum<_lanczosCoreSize || samplenum>=sampleCount-1){
            res=0.0;
        }
        else
        {
            float x =  -_lanczosCoreSize+ ((double)samplenum/sampleCount)*2*_lanczosCoreSize ;

            double mx = sin_x(M_PI*x);
            double mxa =sin_x(M_PI*x/_lanczosCoreSize);
            float popo = pow(M_PI,2)*pow(x,2);
            float numy= _lanczosCoreSize*mx*mxa;
//            if(numy<0.0001){
//                res=0.0;
//            }
//            else{
                res =  (double)numy/popo;
//            }
        }
        core[samplenum]=res;
    }
    return core;
}


QVector<double>  DSPHelper::getLanckosz  (const QVector<double> *src,int width)const
{
    int SampleSize = src->count();

    QVector<int> samplePlaces(SampleSize);
    QVector<double> shapedWave(width);

    int sample,lastsample=-1;


    for(int i(0);i<width;i++)
    {
        shapedWave[i]=0;
        double lDone = (double)i/width;
        sample = (SampleSize)*lDone;
        if(lastsample!=sample)
        {
            samplePlaces[sample]=i;
            lastsample =sample;
        }
    }


    int tw =  width/SampleSize;
    int twm = tw*2*_lanczosCoreSize;
    QVector<double>  core =getLanczosCore(1+twm*100);

    for(int lSample(0);lSample<width;lSample++)
    {
        double lDone = (double)lSample/width;
        sample = SampleSize*lDone;
        double res;
        if(lastsample!=sample)
        {
            res = src->at(sample);
            lastsample =sample;
        }
        else
        {
            res=0;
            if(sample+1<SampleSize)
            {
                double cProp = (double)(lSample-samplePlaces[sample]) / (samplePlaces[sample+1]-samplePlaces[sample]);
                for(int j(0);j<2*_lanczosCoreSize;j++)
                {
                    int snum = sample-_lanczosCoreSize+j+1;
                    double coreProp = (j+(1-cProp))/(2*_lanczosCoreSize);
                    if(snum>=0 && snum<SampleSize )
                    {
                        int corecell= (coreProp) *(core.size());
                        double v=core.at(corecell);
                        double trueValue = src->at(snum);
                        res +=  trueValue*v;
                    }
                }
            }else{
                res = src->at(sample) ;
            }
        }
        shapedWave[lSample] = res;
    }

    return shapedWave;
}
