#include "MainWindowQRCodeGenerator.hpp"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindowQrCodeGenerator mainWindow;

    mainWindow.show();

    return app.exec();
}
