#include "imageprovider.h"

ImageProvider::ImageProvider()
{
    setupImages(":/images/rotary");
}

void ImageProvider::setupImages(QString path){
    QDirIterator it( path,QDirIterator::Subdirectories);
    while (it.hasNext())
    {

        QFileInfo qif = it.fileInfo();
        QString fileName = qif.absoluteFilePath();
                it.next();
        if(qif.isFile())
        {
            QImage *qi = new QImage(fileName);
            if(!qi->isNull()){
                _rotary.append(qi);
            }
        }
//            QFile file(  ":/images/rotary/ROTARY.png" );
    }
}

QImage *ImageProvider::getImageFromMIDIValue(int value)
{
    if(_rotary.size()<=0) return NULL;
    int rvalue= value * (_rotary.size()-1)/127;
    return _rotary.at(rvalue);
}





