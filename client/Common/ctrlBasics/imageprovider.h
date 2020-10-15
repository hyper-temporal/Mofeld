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
        static ImageProvider    instance; // Guaranteed to be destroyed.
                                        // Instantiated on first use.
        return instance;
    }
    QImage *getImageFromMIDIValue(int value);
    void update(int vW,int vH);
private:
    ImageProvider();
    ImageProvider(ImageProvider const&);// Don't Implement
    void operator=(ImageProvider const&);
    void setupImages(QString path);
};

#endif // IMAGEPROVIDER_H
