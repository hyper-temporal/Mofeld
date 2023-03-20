#include "guiBlofMainwindow.h"

#include <QtGui>
#include <QToolBar>
#include <QDockWidget>


ctrlMainSynthaware::ctrlMainSynthaware()
    :_editor_global(this)
{
    initMetaTypeSystem();
    QToolBar *channelToolBar;
    channelToolBar = addToolBar(tr("Blofeld Toolbar"));
//    channelToolBar->setFloatable(false);
    channelToolBar->setMovable(false);
    channelToolBar->addWidget(_editor_global.geOperationView());



    QDockWidget *dockWidget2 = new QDockWidget("Instrument") ;
    dockWidget2->setWidget(_editor_global.getEditorWidget());
    dockWidget2->layout()->setSizeConstraint(QLayout::SetMinimumSize);
    addDockWidget(Qt::LeftDockWidgetArea ,  dockWidget2 );
//    dockWidget2->hide();

    QDockWidget *dockWidget1 = new QDockWidget("Total Recall") ;
    dockWidget1->setWidget(&_editor_global);
    dockWidget1->layout()->setSizeConstraint(QLayout::SetMinimumSize);
    addDockWidget(Qt::LeftDockWidgetArea ,  dockWidget1 );
    dockWidget1->hide();

    QDockWidget *dockWidget3 = new QDockWidget("WaveTable  Editor") ;
    dockWidget3->setWidget(_editor_global.getWaveTableEditor());
    dockWidget3->layout()->setSizeConstraint(QLayout::SetMinimumSize);
    dockWidget3->hide();
    addDockWidget(Qt::LeftDockWidgetArea,  dockWidget3 );
//not working yet
//    QDockWidget *dockWidget4 = new QDockWidget("Multi  Editor") ;
//    dockWidget4->setWidget(_editor_global.getMultiEditor());
//    dockWidget4->layout()->setSizeConstraint(QLayout::SetMinimumSize);
//    dockWidget4->hide();
//    addDockWidget(Qt::LeftDockWidgetArea,  dockWidget4 );

    tabifyDockWidget(dockWidget2,dockWidget3);
    QList<QDockWidget*> lw =this->tabifiedDockWidgets(dockWidget3);
    foreach(QDockWidget *dw , lw){
        dw->isFloating();
    }
    QAction *quitAction = new QAction(tr("E&xit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    connect(quitAction, SIGNAL(triggered()),qApp, SLOT(closeAllWindows()));

//    updateStyle();
    setMinimumSize(0,0);

    channelToolBar->installEventFilter(this);
    _editor_global.installEventFilter(this);

    _editor_global.setFocus();
}



//void  ctrlMainSynthaware::updateStyle(QString s){
//    if(s==""){
//        loadStyleSheet(":/qss/pagefold.qss");
//    }
//    else{
//        loadStyleSheet(s);
//    }
//}

void ctrlMainSynthaware::loadStyleSheet(const QString &sheetName){
    QFile file( sheetName );
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
}


ctrlMainSynthaware::~ctrlMainSynthaware()
{
}

void ctrlMainSynthaware::keyPressEvent(QKeyEvent *e)
{
    int sgsg= e->key();

    if (sgsg == Qt::Key_G){
        emit k_generate();
    }
    else if (sgsg >= Qt::Key_0 && sgsg <= Qt::Key_9 ){
//        _editor_global.callActionN(sgsg-Qt::Key_0);
    }
    //ça pourrai aller jusqua f32!
    else if (sgsg >= Qt::Key_F1 && sgsg <= Qt::Key_F12 ){
//        _editor_global.callActionF(sgsg-Qt::Key_F1);
    }
    else if (sgsg == Qt::Key_Control){

        _ctrl=true;
        emit k_Drawers4Phase();

    }
    else if (sgsg == Qt::Key_Alt){
        _alt=true;
    }
    else if (sgsg == Qt::Key_Up){
        if(_ctrl){
            emit k_nextWaveTable();
        }else{
            emit k_NextFrequency();
        }
    }
    else if (sgsg == Qt::Key_Down){
        if(_ctrl){
            emit k_prevWaveTable();
        }else{
            emit k_PrevFrequency();
        }
    }
    else if (sgsg == Qt::Key_Left){
        if(_ctrl){
            emit k_PrevTable();
        }else{
            emit k_prevWave();
        }
    }
    else if (sgsg == Qt::Key_Right){
        if(_ctrl){
            emit k_NextTable();
        }else{
            emit k_nextWave();
        }
    }
    else if(sgsg == Qt::Key_P)
    {
        emit k_Drawers4RotationPH(true);
    }
    else if(sgsg == Qt::Key_O)
    {
        emit k_Drawers4RotationMG(true);
    }
    else if(sgsg == Qt::Key_I)
    {
        emit k_Drawers4RotationT(true);
    }
    else if(sgsg == Qt::Key_M){
        if(_maj){
        }
    }

    QWidget::keyPressEvent(e);

}

void ctrlMainSynthaware::keyReleaseEvent(QKeyEvent *e)
{
    int sgsg= e->key();

    if (sgsg == Qt::Key_Control){
        _ctrl=false;
        emit k_Drawers4Mag();
    }
    else if (sgsg == Qt::Key_Alt){
        _alt=false;
    }
    else if (sgsg == Qt::Key_Shift){
            _maj=false;
    }
    else if(sgsg == Qt::Key_P)
    {
        emit k_Drawers4RotationPH(false);
    }
    else if(sgsg == Qt::Key_O)
    {
        emit k_Drawers4RotationMG(false);
    }
    else if(sgsg == Qt::Key_I)
    {
        emit k_Drawers4RotationT(false);
    }
    QWidget::keyReleaseEvent(e);
}


bool ctrlMainSynthaware::eventFilter(QObject * obj, QEvent * event)
{


           if (event->type() == QEvent::KeyPress) {
               QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
               keyPressEvent(keyEvent);
               return true;
           } else if (event->type() == QEvent::KeyRelease){
               QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
               keyReleaseEvent(keyEvent);
               return true;
           }
            else {
                   // pass the event on to the parent class
                   return QMainWindow::eventFilter(obj, event);
               }
}

void ctrlMainSynthaware::initMetaTypeSystem (){
    qRegisterMetaType<std::vector<uchar> >("std::vector<uchar>");
    qRegisterMetaType<Arrangement>();
    qRegisterMetaType<SignalReal>();
    qRegisterMetaType<Instrument>();
    qRegisterMetaType<Propriete>();
    qRegisterMetaType<BlofChannel>();
    qRegisterMetaType<Contrainte>();
    qRegisterMetaType<BlofeldWaveTableMgrModel>();
}


void ctrlMainSynthaware::closeEvent(QCloseEvent *){
    _editor_global.close();
}



