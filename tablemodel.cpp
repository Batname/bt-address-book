#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

TableModel::TableModel(QList<QPair<QString, QString> > pairs, QObject *parent)
    : QAbstractTableModel(parent)
{
    listofPairs = pairs;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return listOfPAirs.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVrariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if(index.row() >= listOfPAirs.size() || index.row() < 0) return QVariant();

    if(role == Qt::DisplayRole) {
        QPair<QString, QString> pair = listOfPAirs.at(index.row());

        if (index.column() == 0) return pair.first;
        else if (index.column() == 1) return pair.second;
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Name");
            case 1:
                return tr("Address");

            default:
                return QVariant();
        }
    }
    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);

    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row) listOfPAirs.removeAt(position);

    endRemoveRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows -1);

    for (int row = 0; row < rows; ++row) listOfPAirs.removeAt(position);

    endRemoveRows();
    return true;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role = Qt::EditRole) {
        int row = index.row();

        QPair<QString, QString> p = listOfPAirs.value(row);

        if (index.column() == 0) p.first = value.toString();
        else if (index.column() == 1) p.second = value.toString();
        else return false;

        listOfPAirs.replace(row, p);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) || Qt::ItemIsEnabled;
}

QList<QPair<QString, QString>> TableModel::getList()
{
    return listOfPAirs;
}
