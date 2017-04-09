#include "draggable.h"

Draggable::Draggable():QDockWidget()
{
    Qt::WindowFlags flags = 0;
    flags = Qt::Window;
    flags |= Qt::WindowTitleHint;
    flags |= Qt::CustomizeWindowHint;
    flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);
//setTitleBarWidget(new QWidget(NULL));
    setFeatures(DockWidgetFloatable | DockWidgetMovable);

  }
//! [1]
void Draggable::show()
{
    showMinimized();
}
////! [1]
//void Draggable::mousePressEvent(QMouseEvent *event)
//{

//    if (event->button() == Qt::LeftButton) {
//        dragPosition = event->globalPos() - frameGeometry().topLeft();
//        event->accept();
//    }
//}
////! [1]

////! [2]
//void Draggable::mouseMoveEvent(QMouseEvent *event)
//{
//    if (event->buttons() & Qt::LeftButton) {
//        move(event->globalPos() - dragPosition);
//        event->accept();
//    }
//}
//! [2]


