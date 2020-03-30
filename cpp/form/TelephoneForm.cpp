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
