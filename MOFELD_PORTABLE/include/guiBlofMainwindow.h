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

#include "miomgr.h"
#include "defs.h"
#include "blofeldwindows.h"

//etat synchrone: arrangement - instrument = parametre
// persistance
class ctrlMainSynthaware
        : public QMainWindow
{
   Q_OBJECT
//gestion clavier
    bool _ctrl,_alt,_maj,_up,_down,_left,_right;

    QToolBar *_wGlobalCtrl;
    BlofeldViews *_editor_global;
    QTabWidget * _globalTabs;

    QAction *actionQuitter;

public:
//ACTIONS:
    /*

      TODO
      -permettre de choisir de passer a la table suivante sur realease seulement
      -permettre le dépassement des valeurs max en fréquence idft normale puis dft on n'écrète qu'au relachement
      -implémenter translation (ALT)
      -implémenter modification de la phase(MAJ)
      -navigation WT avec fleches (H:WaveNumber, V:TableNumber)
*/
    /* pistes
     Conception de nouveaux controle graphiques
        - vue globalisée façon empreinte sonore
        - lissage avec lancosz
        -implémentation d'une navigation au travers de fichiers sons
*/
    /*
        MIDI
        -démon de midi...vraiment cad un service auxquelles s'inscrives les applications pour le routage de leurs donnnées midi
        -séquencage disociation temps réel / sysex
        -routage
        -filtrage
        -transformation
        -validation
        -priorisation
        -
*/
/*
    SEQUENCEURS:
    filtre entrée de notes et déclenche des boucles ma,nipulables par des controles
    velocité

*/

    /*
        Sortir le projet de composition des messages qui est a revoir
        le systeme de multiwidget pour dessinner est a refaire: 1 seul wgt au lieu de 128 ...par tableau, tout ça pour dessiner UNE seule forme...
        la persistance doit etre réaliser avec une base sqlite, ou xml,json et fichier midi
        capacité d'envoyer des dumps
        gestion partitions
        session.contexte.instrument.intervention.evenement
        mise en place d'un parser d'opérations entre les signaux
        message/mot actions(transformation,filtrage,modification),
 conditionnalité:
            gestion de la temporalité du  message
        +   déclenche des evenements si les conditions sont réunies conditionneur executeur
*/
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
    void actWindShowEditor(bool checked);

public slots:
    void updateStyle(QString s="");
private:
    void loadStyleSheet(const QString &sheetName);

 };

#endif // MAINWINDOW_H

