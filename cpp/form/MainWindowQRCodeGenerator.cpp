#include "MainWindowQRCodeGenerator.hpp"
#include "LinkCreatForm.hpp"
#include "ui_MainWindowQRCodeGenerator.h"
#include "vCardCreateForm.hpp"

MainWindowQrCodeGenerator::MainWindowQrCodeGenerator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowQrCodeGenerator)
{
    ui->setupUi(this);
}

MainWindowQrCodeGenerator::~MainWindowQrCodeGenerator()
{
    delete ui;
}

void MainWindowQrCodeGenerator::on_actionvCard_triggered()
{
    this->removeWidget();
    QWidget *widget = new vCardCreateForm(this);
    this->ui->centralwidget->layout()->addWidget(widget);
}

void MainWindowQrCodeGenerator::on_actionLink_triggered()
{
    this->removeWidget();
    QWidget *widget = new LinkCreatForm(this);
    this->ui->centralwidget->layout()->addWidget(widget);
}

void MainWindowQrCodeGenerator::removeWidget()
{

    if(!this->ui->centralwidget->layout()->count())
        return;

    QLayoutItem *lItem = this->ui->centralwidget->layout()->takeAt(0);

    if(lItem->widget() != nullptr)
    {
        lItem->widget()->setParent(nullptr);
        delete lItem;
    }
}
