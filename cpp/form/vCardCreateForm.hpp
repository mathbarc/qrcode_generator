#ifndef VCARDCREATEFORM_HPP
#define VCARDCREATEFORM_HPP

#include <QWidget>

namespace Ui {
    class vCardCreateForm;
}

class vCardCreateForm : public QWidget
{
        Q_OBJECT

    public:
        explicit vCardCreateForm(QWidget *parent = nullptr);
        ~vCardCreateForm();

    private slots:
        void on_pushButton_2_clicked();

        void on_pushButton_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_generate_clicked();

    private:
        Ui::vCardCreateForm *ui;
};

#endif // VCARDCREATEFORM_HPP
