#include "guiBlofMainwindow.h"
#include "BlofeldMgr/blofeldreplica.h"
#include "genericity//entitydao.h"
#include "genericity/combotool.h"

#include <QtGui>

using namespace OperationProps;

ctrlMainSynthaware::ctrlMainSynthaware()
{
    initMetaTypeSystem();

    _editor_global = new BlofeldViews(this);
    QToolBar *channelToolBar;
    channelToolBar = addToolBar(tr("Blofeld Toolbar"));
    channelToolBar->setMovable(false);
    channelToolBar->addWidget(_editor_global->geOperationView());

    QDockWidget *dockWidget1 = new QDockWidget("Total Recall") ;
    dockWidget1->setWidget(_editor_global->getTargetWidget());
    dockWidget1->layout()->setSizeConstraint(QLayout::SetMinimumSize);
    addDockWidget(Qt::RightDockWidgetArea ,  dockWidget1 );

    QDockWidget *dockWidget2 = new QDockWidget("Instrument") ;
    dockWidget2->setWidget(_editor_global->getEditorWidget());
    dockWidget2->layout()->setSizeConstraint(QLayout::SetMinimumSize);
    addDockWidget(Qt::LeftDockWidgetArea ,  dockWidget2 );


    QDockWidget *dockWidget3 = new QDockWidget("WaveTable  Editor") ;
    dockWidget3->setWidget(_editor_global->getWaveTableEditor());
    dockWidget3->layout()->setSizeConstraint(QLayout::SetMinimumSize);
    addDockWidget(Qt::LeftDockWidgetArea,  dockWidget3 );

    QDockWidget *dockWidget4 = new QDockWidget("Multi") ;
    dockWidget4->setWidget(_editor_global->getMultiView());
    dockWidget4->hide();
    addDockWidget(Qt::LeftDockWidgetArea ,  dockWidget4 );

    tabifyDockWidget(dockWidget1,dockWidget2);
    tabifyDockWidget(dockWidget2,dockWidget3);
    tabifyDockWidget(dockWidget3,dockWidget4);

    QAction *quitAction = new QAction(tr("E&xit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    connect(quitAction, SIGNAL(triggered()),qApp, SLOT(closeAllWindows()));

    updateStyle();
}


void ctrlMainSynthaware::actWindShowEditor(bool checked)
{
    if(checked==true){
        _wGlobalCtrl->show();
    }else{
        _wGlobalCtrl->hide();
    }
}


void  ctrlMainSynthaware::updateStyle(QString s){
    if(s=="")
    {
        loadStyleSheet(":/qss/pagefold.qss");
    }
    else{
        loadStyleSheet(s);
    }
}

void ctrlMainSynthaware::loadStyleSheet(const QString &sheetName){
    QFile file( sheetName );
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
}


ctrlMainSynthaware::~ctrlMainSynthaware()
{
    delete _editor_global;
}

void ctrlMainSynthaware::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_G){
    }
    else if (e->key() == Qt::Key_Control){
    }
    else
        QWidget::keyPressEvent(e);
}

void ctrlMainSynthaware::keyReleaseEvent(QKeyEvent *e)
{
    QWidget::keyReleaseEvent(e);
}

void ctrlMainSynthaware::initMetaTypeSystem (){

    qRegisterMetaType<std::vector<uchar> >("std::vector<uchar>");
    qRegisterMetaTypeStreamOperators<Arrangement>("Arrangement");
    qMetaTypeId<Arrangement>();
    qRegisterMetaTypeStreamOperators<Instrument>("Instrument");
    qMetaTypeId<Instrument>();
    qRegisterMetaTypeStreamOperators<Propriete>("Propriete");
    qMetaTypeId<Propriete>();
    qRegisterMetaTypeStreamOperators<BlofChannel>("BlofChannel");
    qMetaTypeId<BlofChannel>();
    qRegisterMetaTypeStreamOperators<Contrainte>("Contrainte");
    qMetaTypeId<Contrainte>();
    qRegisterMetaTypeStreamOperators<BlofeldWaveTableMgrModel>("BlofeldWaveTableMgrModel");
    qMetaTypeId<BlofeldWaveTableMgrModel>();

}


void ctrlMainSynthaware::closeEvent(QCloseEvent *){
    _editor_global->close();
}



