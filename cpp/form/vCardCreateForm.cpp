#include "vCardCreateForm.hpp"
#include "ui_vCardCreateForm.h"

vCardCreateForm::vCardCreateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vCardCreateForm)
{
    ui->setupUi(this);
}

vCardCreateForm::~vCardCreateForm()
{
    delete ui;
}
