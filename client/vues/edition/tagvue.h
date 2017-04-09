#ifndef TAGVUE_H
#define TAGVUE_H

#include <QCompleter>
#include <QLineEdit>
#include <QPushButton>
#include <QAbstractItemModel>
#include <QStringListModel>
#include <QFile>
#include <QModelIndex>
#include <QCompleter>
#include <QGridLayout>


class TagVue: QWidget
{
public:
    QAbstractItemModel * _model;
    QCompleter *completer;
    QLineEdit *lineEdit;
    QPushButton * addCat;
    QPushButton * RemoveCat;
    QGridLayout * layout;

    TagVue();
    void SetModel(QString modelPath);
    QGridLayout * getLayout(){return layout;}

    QStringList GetTags();
    void AddTag(QString s);
    QAbstractItemModel *   modelFromFile(const QString& fileName);

};

#endif // TAGVUE_H
