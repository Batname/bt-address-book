#include "newaddresstab.h"
#include "adddialog.h"

#include <QWidget>

NewAddressTab::NewAddressTab(QWidget *parent)
    : QWidget(parent)
{
    Q_UNUSED(parent);

    descriptionLabel = new QLabel(tr("There are currently no contacts in your address book. ", "\nClick  Add to add now contacts."));

    addButton = new QPushButton(tr("add"));

    connect(addButton, &QAbstructButton::clicked, this, &NewAddressTab::addEntry);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(addButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}

void NewAddressTab::addEntry()
{
    AddDialog aDialog;

    if(aDialog.exec()) {
        QString name = aDialog.nameText->text();
        QString address = aDialog.addressText->toPlainText();

        emit sendDetails(name, address);
    }
}
