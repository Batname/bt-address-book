#ifndef ADDRESSWIDGET_H
#define ADDRESSWIDGET_H

//#include "newaddresstab.h"
//#include "tabmodel.h"

#include <QItemSelection>
#include <QTabWidget>

//QT_BEGIN_NAMESPACE
//class QSortFilterProxyModel;
//class QItemSelectionModel;
//QT_END_NAMESPACE

class AddressWidget : public QTabWidget
{
//    Q_OBJECT

public:
    AddressWidget(QWidget *parent = 0);

public slots:
signals:
private:
    void setupTabs();
};

#endif // ADDRESSWIDGET_H
