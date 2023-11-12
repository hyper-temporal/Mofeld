#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QImage>
#include <QDirIterator>

#define imageProvider ImageProvider::getInstance()

class ImageProvider
{
    QVector<QImage*> _rotary;

public:

    static ImageProvider& getInstance()
    {
        static ImageProvider    instance;
        return instance;
    }
    QImage *getImageFromMIDIValue(int value);
    void update(int vW,int vH);
private:
    ImageProvider();
    ImageProvider(ImageProvider const&);
    void operator=(ImageProvider const&);
    void setupImages(QString path);
};

#endif // IMAGEPROVIDER_H
