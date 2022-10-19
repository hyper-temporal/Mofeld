#ifndef DRAGGABLE_H
#define DRAGGABLE_H

#include <QToolBar>
#include <QDockWidget>
#include <QMouseEvent>
#include <QAction>

class Draggable
        :public QDockWidget
{
    QPoint dragPosition;
public:
    Draggable();
protected:
    void show();
//    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);
};



#endif // DRAGGABLE_H
