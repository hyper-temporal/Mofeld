#include "tagvue.h"

TagVue::TagVue()
{
    lineEdit = new QLineEdit;
    QSize buttonSize(30,20);

    addCat = new QPushButton(QIcon(),"+",this);
    addCat->setText("+");
    addCat->setFixedSize(buttonSize);
    RemoveCat = new QPushButton(QIcon(),"-",this);
    RemoveCat->setText("-");
    RemoveCat->setFixedSize(buttonSize);

    QWidget * Dummy = new QWidget();
    layout = new QGridLayout;
    layout->addWidget(lineEdit, 0,0, 0,4,Qt::AlignLeft);
    layout->addWidget(Dummy, 0, 1, 0,1,Qt::AlignRight );
    layout->addWidget(Dummy, 0, 2, 0,1,Qt::AlignRight );
    layout->addWidget(Dummy, 0, 3, 0,1,Qt::AlignRight );
    layout->addWidget(addCat, 0, 4, 0,1,Qt::AlignRight );
    layout->addWidget(RemoveCat, 0, 5, 0,1,Qt::AlignRight);
    SetModel("./Datas/catList.txt");
    lineEdit->setFocus();
}

void TagVue::SetModel(QString s)
{
    _model = modelFromFile(s);
    completer->setMaxVisibleItems(10);
    completer->setModel(_model);
    completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWrapAround(true);
    completer->setCompletionMode( QCompleter::PopupCompletion);
    lineEdit->setCompleter(completer);
}



QAbstractItemModel * TagVue::modelFromFile(const QString& fileName)
{
    completer = new QCompleter(this);

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(completer);
    QStringList words;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << line.trimmed();
    }
   return new QStringListModel(words, completer);

}
