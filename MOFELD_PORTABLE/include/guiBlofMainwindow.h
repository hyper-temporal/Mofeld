#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMouseEvent>
#include <QMainWindow>
#include <QStandardItemModel>
#include <QFile>
#include <QSettings>
#include <QMessageBox>
#include <QStringList>
#include <QStringListModel>
#include <QDataWidgetMapper>
#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QGridLayout>
#include <QKeyEvent>
#include "blofeldwindows.h"

class ctrlMainSynthaware
        : public QMainWindow
{
   Q_OBJECT
    bool _ctrl,_alt,_maj,_up,_down,_left,_right;
    BlofeldViews _editor_global;
public:
    ctrlMainSynthaware();
    ~ctrlMainSynthaware();
    static void initMetaTypeSystem();
protected:
    bool eventFilter(QObject *, QEvent *);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
signals:
    void k_generate();
    void k_onModifyStretch();
    void k_onModifyRestrict();
    void k_CopyWave();
    void k_PasteWave();
    void k_prevWaveTable();
    void k_nextWaveTable();
    void k_NextFrequency();
    void k_PrevFrequency();
    void k_NextTable();
    void k_PrevTable();
    void k_nextWave();
    void k_prevWave();
    void k_Drawers4RotationPH(bool);
    void k_Drawers4RotationMG(bool);
    void k_Drawers4RotationT(bool);
    void k_Drawers4Mag();
    void k_Drawers4Phase();

private slots:
    void closeEvent(QCloseEvent *);

private:
    void loadStyleSheet(const QString &sheetName);

 };

#endif // MAINWINDOW_H

