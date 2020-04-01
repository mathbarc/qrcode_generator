#include "TelephoneForm.hpp"
#include "ui_TelephoneForm.h"

TelephoneForm::TelephoneForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelephoneForm)
{
    ui->setupUi(this);
}

TelephoneForm::~TelephoneForm()
{
    delete ui;
}

std::string TelephoneForm::getVCardEntry() const
{
    std::string entry = "TEL";
    int type = this->ui->comboBox->currentIndex();

    if(type == 0)
    {
        entry+=";TYPE=CELL";
    }
    else if(type == 1)
    {
        entry+=";TYPE=WORK";
    }
    else if(type == 2)
    {
        entry+=";TYPE=HOME";
    }

    entry+=":"+this->ui->lineEdit_telephone->text().toStdString()+"\n";

    return entry;
}
