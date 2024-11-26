#include "LinkCreatForm.hpp"
#include "ui_LinkCreatForm.h"

#include <QFileDialog>
#include <QMessageBox>

#include <fstream>

#include "QrCode.hpp"
#include <QDir>

LinkCreatForm::LinkCreatForm(QWidget *parent) : QWidget(parent), ui(new Ui::LinkCreatForm)
{
    ui->setupUi(this);
}

LinkCreatForm::~LinkCreatForm()
{
    delete ui;
}

void LinkCreatForm::on_pushButton_clicked()
{
    std::string url = this->ui->lineEdit_link->text().toStdString();

    if(url.empty())
    {
        QMessageBox::warning(this, "Link Vazio", QString::fromUtf8("O campo URL não está preenchido."));
        return;
    }

    QString path = QFileDialog::getSaveFileName(this, "Arquivo QRCode", QDir::homePath() + "/QrCodeImage.svg", "*.svg");
    if(path.isEmpty())
        return;

    std::string pathToImage = path.toStdString();

    std::ofstream file(pathToImage);

    qrcodegen::QrCode qrCode = qrcodegen::QrCode::encodeText(url.c_str(), qrcodegen::QrCode::Ecc::LOW);

    file << qrCode.toSvgString(4);
    file.close();
}
