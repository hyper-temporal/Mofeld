#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMouseEvent>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QFile>
#include <QSettings>
#include <QMessageBox>
 #include "Midi/miomgr.h"
 #include "defs.h"

#include <QStringList>
#include <QStringListModel>
#include <QDataWidgetMapper>
#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QGridLayout>



#include "defs.h"
#include "client/vues/blofeldwindows.h"

//etat synchrone: arrangement - instrument = parametre
// persistance
class ctrlMainSynthaware
        : public QMainWindow
{
   Q_OBJECT

    QToolBar *_wGlobalCtrl;
    BlofeldViews *_editor_global;
    QTabWidget * _globalTabs;

    QAction *actionQuitter;

public:

    ctrlMainSynthaware();
    ~ctrlMainSynthaware();

    static void initMetaTypeSystem();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void closeEvent(QCloseEvent *);
    void actWindShowEditor(bool checked);

public slots:
    void updateStyle(QString s="");
private:
    void loadStyleSheet(const QString &sheetName);

 };

#endif // MAINWINDOW_H

