#ifndef MAINWINDOWQRCODEGENERATOR_HPP
#define MAINWINDOWQRCODEGENERATOR_HPP

#include <QMainWindow>

namespace Ui {
    class MainWindowQrCodeGenerator;
}

class MainWindowQrCodeGenerator : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindowQrCodeGenerator(QWidget *parent = nullptr);
        ~MainWindowQrCodeGenerator();

        void removeWidget();

    private slots:
        void on_actionvCard_triggered();

        void on_actionLink_triggered();

    private:
        Ui::MainWindowQrCodeGenerator *ui;
};

#endif // MAINWINDOWQRCODEGENERATOR_HPP
