#include "irealsignal.h"

IRealSignal::IRealSignal(int size)
{
    setSize(size);
}


void IRealSignal::setSize(int size)
{
    //La taille du vecteur est positive et paire
    if(size%2){
        throw ("le buffer doit posseder un nombre d'echantillons pair!!!");
    }
    if(size<=0){
        throw ("la taille du buffer doit etre positive");
    }
    _size = size;
}
