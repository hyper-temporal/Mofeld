#ifndef FRMSYNTHCTRL_ROTARY_H
#define FRMSYNTHCTRL_ROTARY_H

#include "ctrlparamleaf.h"
#include "imageprovider.h"

class DialMaison
        :public QDial
{
    int _angle;
public :
    DialMaison(QWidget*w):QDial(w)
    {}
//TODO: faire des controles cool...
    /*
controles resistants 3d
balles
bumpers
elements
velocite
action reponse instancié ->cycles, modulations:
*/

    /*
 dessin!
rond triangle carrés , polygones ;.. pour donner des formes
poussoirs aspirateur, découpeur, explosion(rerépartition )
déplacement par liaison donnant l'éloignement mais soumises aux velocités adverses
resulte de ces parametre et leur soumet une réponse(modification de leur etats selon )
*/
    void paintEvent(QPaintEvent *)
    {
        int v= std::min(width(),height());

         QImage *image = imageProvider.getImageFromMIDIValue(value());
         if(image !=NULL){
             QPainter painter(this);
             painter.setRenderHint(QPainter::Antialiasing, true);
             painter.drawImage( rect(),image->scaled(v,v,Qt::KeepAspectRatio,Qt::SmoothTransformation));
         }
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
