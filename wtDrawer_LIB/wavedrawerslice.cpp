#include "wavedrawerslice.h"

DrawerSlice::DrawerSlice(QWidget *parent)
    :QWidget(parent)
{}


void DrawerSlice::paintEvent(QPaintEvent * pe)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    paintDomain(painter);
}


