#include "client/vues/guiBlofMainwindow.h"
#include <QApplication>
#include "runguard.h"
#include "defs.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    RunGuard guard( "DontHurtYourBack" );
    if ( guard.tryToRun() )
    {
        ctrlMainSynthaware w;
        w.show();
        return a.exec();

    }
    a.quit();
    exit(0);
}
