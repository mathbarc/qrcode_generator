#include "MainWindowQRCodeGenerator.hpp"
#include <QApplication>

<<<<<<< HEAD
int main(int argc, char **argv) {
  QApplication app(argc, argv);
=======
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
>>>>>>> b1cbd87fac745c9b3e60ad5e0dc6cbb17b465f06

  MainWindowQrCodeGenerator mainWindow;

  mainWindow.show();

  return app.exec();
}
