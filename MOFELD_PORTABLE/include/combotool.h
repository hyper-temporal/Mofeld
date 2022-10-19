#ifndef COMBOACTION_H
#define COMBOACTION_H

#include <QAbstractListModel>
#include "BlofeldEnums.h"

//classe dont le seull role est de facilite l'utilisation des combobox avec les enums
class ComboTool
        : public  QAbstractListModel
{
    Q_OBJECT

protected:
    const SynthEnum* _enum;
public:
    ComboTool( const SynthEnum* e ):_enum(e)
    {}

    int rowCount(const QModelIndex &parent = QModelIndex())const{
        return _enum->CountElements();
    }

    QVariant data(const QModelIndex &index, int role) const
    {
        if (!index.isValid())
            return QVariant();

        if (index.row() >= rowCount() || index.row() < 0)
            return QVariant();

        if (role == Qt::DisplayRole) {
            if(index.column()==0){
                return _enum->getElement(index.row())->LaChaine;
            }else{
                return _enum->getElement(index.row())->Lentier;
            }
        }
        return QVariant();
    }
};





#endif // COMBOACTION_H
