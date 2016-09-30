#include "adddialog.h"

#include <QWidget>

AddDialog::AddDialog(QWidget *parent = 0)
    : QDialog(parent)
{
    nameLabel = QLabel("Name");
    addressLabel = QLabel("Address");
    okButton = QPushButton("Ok");
    cancelButton = QPushButton("Cancel");

    nameText = new QLineEdit;
    addressText = new QTextEdit;

    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(addressLabel, 1, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(addressText, 1, 1, Qt::AlignLeft);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 1, 2, Qt::AlignLeft);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);

    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::click, this, QDialog::accept);
    connect(cancelButton, &QAbstractButton::click, this, QDialog::reject);

    setWindowTitle(tr("Add a contact"));
}
