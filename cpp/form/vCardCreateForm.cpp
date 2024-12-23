#include "vCardCreateForm.hpp"
#include "ui_vCardCreateForm.h"

#include <QFileDialog>
#include <QLineEdit>
#include <fstream>
#include <iostream>

#include "QrCode.hpp"
#include "TelephoneForm.hpp"

vCardCreateForm::vCardCreateForm(QWidget *parent) : QWidget(parent), ui(new Ui::vCardCreateForm)
{
    ui->setupUi(this);
}

vCardCreateForm::~vCardCreateForm()
{
    delete ui;
}

void vCardCreateForm::on_pushButton_2_clicked()
{
    QWidget *wid = static_cast<QWidget *>(new TelephoneForm(this->ui->widget_telephone));
    this->ui->widget_telephone->layout()->addWidget(wid);
}

void vCardCreateForm::on_pushButton_clicked()
{
    QWidget *wid = new QLineEdit(this->ui->widget_email);
    this->ui->widget_email->layout()->addWidget(wid);
}

void vCardCreateForm::on_pushButton_3_clicked()
{
    QWidget *wid = new QLineEdit(this->ui->widget_sites);
    this->ui->widget_sites->layout()->addWidget(wid);
}

void vCardCreateForm::on_pushButton_generate_clicked()
{
    std::string vCard = "BEGIN:VCARD\n"
                        "VERSION:3.0\n";

    QString name = this->ui->lineEdit_name->text();
    vCard += "FN:" + name.toStdString() + "\n";
    QStringList slName = name.split(" ");
    if(slName.size() > 0)
    {
        vCard += "N:";

        for(int i = slName.size() - 1; i >= 0; i--)
        {
            vCard += slName[i].toStdString() + ";";
        }

        vCard += "\n";
    }

    if(!this->ui->lineEdit_org->text().isEmpty())
        vCard += "ORG:" + this->ui->lineEdit_org->text().toStdString() + "\n";

    if(!this->ui->lineEdit_cargo->text().isEmpty())
        vCard += "ROLE:" + this->ui->lineEdit_cargo->text().toStdString() + "\n";

    if(!this->ui->lineEdit_rua->text().isEmpty() && !this->ui->lineEdit_num_rua->text().isEmpty() &&
       !this->ui->lineEdit_bairro->text().isEmpty() && !this->ui->lineEdit_cidade->text().isEmpty() &&
       !this->ui->lineEdit_estado->text().isEmpty() && !this->ui->lineEdit_cep->text().isEmpty())
    {
        vCard += "ADR:" + this->ui->lineEdit_rua->text().toStdString() + " " +
                 this->ui->lineEdit_num_rua->text().toStdString() + ";" +
                 this->ui->lineEdit_bairro->text().toStdString() + ";" +
                 this->ui->lineEdit_cidade->text().toStdString() + ";" +
                 this->ui->lineEdit_estado->text().toStdString() + ";" + this->ui->lineEdit_cep->text().toStdString() +
                 ";BR;\n";
    }

    for(int i = 0; i < this->ui->widget_telephone->layout()->count(); i++)
    {
        const TelephoneForm *tel =
            static_cast<const TelephoneForm *>(this->ui->widget_telephone->layout()->itemAt(i)->widget());
        vCard += tel->getVCardEntry();
    }

    for(int i = 0; i < this->ui->widget_email->layout()->count(); i++)
    {
        const QLineEdit *email = static_cast<const QLineEdit *>(this->ui->widget_email->layout()->itemAt(i)->widget());
        vCard += "EMAIL:" + email->text().toStdString() + "\n";
    }

    for(int i = 0; i < this->ui->widget_sites->layout()->count(); i++)
    {
        const QLineEdit *site = static_cast<const QLineEdit *>(this->ui->widget_sites->layout()->itemAt(i)->widget());
        vCard += "URL:" + site->text().toStdString() + "\n";
    }

    vCard += "END:VCARD\n";
    //    std::cout<<vCard<<std::endl;

    QString path = QFileDialog::getSaveFileName(this, "Arquivo QRCode", QDir::homePath() + "/QrCodeVCard.svg", "*.svg");
    if(path.isEmpty())
        return;

    std::string pathToImage = path.toStdString();

    std::ofstream file(pathToImage);

    qrcodegen::QrCode qrCode = qrcodegen::QrCode::encodeText(vCard.c_str(), qrcodegen::QrCode::Ecc::LOW);

    file << qrCode.toSvgString(4);
    file.close();
}
