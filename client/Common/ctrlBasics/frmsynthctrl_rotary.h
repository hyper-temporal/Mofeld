#ifndef FRMSYNTHCTRL_ROTARY_H
#define FRMSYNTHCTRL_ROTARY_H

#include "../ctrlparamleaf.h"

class DialMaison
        :public QDial
{
    int _angle;
    const QImage _im;
public :
    DialMaison(QWidget*w):QDial(w),_im(tr("C:/Users/geohn/Desktop/Rotary_255.png"))
    {
    }

    void paintEvent(QPaintEvent *)
    {
        int v= std::min(width(),height());
        QImage image = _im.scaled(v,v,Qt::KeepAspectRatio,Qt::SmoothTransformation);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.translate(width()/2,height()/2);
        painter.rotate(value()*360/128);
        painter.translate(-width()/2,-height()/2);
        painter.drawImage( rect(),image);
    }


};


class frmSynthCtrl_rotary
    :public CtrlParamLeaf
{
    int _offset;
public:
    frmSynthCtrl_rotary(QWidget * parent,
                        const BlofeldReplica *synth,
                        Parametre *param,
                        int offset =0,
                        QBoxLayout::Direction d = QBoxLayout::TopToBottom
                        );
    void setLayout();
    void UpdatedValueDirect(int value);
    void show();
    void hide();
private:
    void reconnecter();
    void deconnecter();
    void directConnect();
    void InitData();

 private slots:
    void ValueChanged(int v);
    void ValueChangedOffset(int v);
    void ValueChangedOffsetDirect(int v);

};

#endif // FRMSYNTHCTRL_ROTARY_H
