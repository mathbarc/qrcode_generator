#ifndef LINKCREATFORM_HPP
#define LINKCREATFORM_HPP

#include <QWidget>

namespace Ui {
    class LinkCreatForm;
}

class LinkCreatForm : public QWidget
{
        Q_OBJECT

    public:
        explicit LinkCreatForm(QWidget *parent = nullptr);
        ~LinkCreatForm();

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::LinkCreatForm *ui;
};

#endif // LINKCREATFORM_HPP
