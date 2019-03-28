#include "myapp.h"
#include "user.h"

#include <QThread>
#include <QDebug>
#include <iostream>
#include <QSqlDatabase>
#include <Windows.h>

MyApp::MyApp(QObject *parent) :
  QObject(parent)
{}

void MyApp::run() {
  User *user;

  HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
  WORD old_clr_attr;
  CONSOLE_SCREEN_BUFFER_INFO buf_info;

  GetConsoleScreenBufferInfo(hd, &buf_info);
  old_clr_attr = buf_info.wAttributes;

  try {
    user = new User(this);
    user->regist();

    for (;;) {
      SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

      std::string cmd;
      std::cin >> cmd;

      if (cmd == "in") {
        user->checkIn();
      }
      else if (cmd == "out") {
        user->checkOut();
      }
      else if (cmd == "on") {
        int temp_init;
        std::cin >> temp_init;
        user->turnOn(temp_init);
      }
      else if (cmd == "off") {
        user->turnOff();
      }
      else if (cmd == "tem") {
        int temp;
        std::cin >> temp;
        user->setTemp(temp);
      }
      else if (cmd == "stt") {
        user->getState();
      }
      else if (cmd == "bil") {
        user->getBilling();
      }
      else {
        SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_INTENSITY);
        this->printUsage();
      }
    }

  } catch (const char *err) {
    std::cerr << "error: ";
    std::cerr << err << std::endl;
    exit(1);
  }
}

void MyApp::printUsage()
{
  std::cerr << "  Usage:\n"
            << "    in:  Check-in and start billing.\n"
            << "    out: Leave and stop billing.\n"
            << "    on:  Turn on the air-conditioner "
               "and set the temperature to a default value.\n"
            << "    off: Turn off the air-conditioner.\n"
            << "    tem: Set the temperature to a given value.\n"
            << "    stt: Get the state of the air-conditioner.\n"
            << "    bil: Get the billing.\n";
}
