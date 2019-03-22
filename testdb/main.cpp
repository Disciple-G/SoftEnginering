#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include "myapp.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
//  QTimer::singleShot(0, &a, SLOT(quit()));

  MyApp *app = new MyApp();
  app->run();

//  return a.exec();
}
