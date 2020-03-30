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

    private:
        Ui::vCardCreateForm *ui;
};

#endif // VCARDCREATEFORM_HPP
