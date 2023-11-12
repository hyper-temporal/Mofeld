#include "draggable.h"

Draggable::Draggable():QDockWidget()
{
    Qt::WindowFlags flags ;
    flags = Qt::Window;
    flags |= Qt::WindowTitleHint;
    flags |= Qt::CustomizeWindowHint;
    flags |= Qt::WindowStaysOnTopHint;
    setWindowFlags(flags);
    setFeatures(DockWidgetFloatable | DockWidgetMovable);

  }
void Draggable::show()
{
    showMinimized();
}


