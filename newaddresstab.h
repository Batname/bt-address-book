#ifndef NEWADDRESSTAB_H
#define NEWADDRESSTAB_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class Qlabel;
class QPushButton;
class QVBoxLayout;
QT_END_NAMESPACE

class NewAddressTab : public QWidget
{
    Q_OBJECT
public:
    NewAddressTab(QWidget *parent = 0);

public slots:
    void addEntry();

signals:
    void sendDetails(QString name, QString address);

private:
    Qlabel *descriptionLabel;
    QPushButton *addButton;
    QVBoxLayout *mainLayout;
};

#endif // NEWADDRESSTAB_H
