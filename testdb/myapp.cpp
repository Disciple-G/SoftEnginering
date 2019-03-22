#include "myapp.h"
#include "hotel.h"

#include <QThread>
#include <QDebug>
#include <iostream>
#include <QSqlDatabase>
#include <Windows.h>

MyApp::MyApp(QObject *parent) :
  QObject(parent)
{}

void MyApp::run() {
  Hotel *hotel;

  HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
  WORD old_clr_attr;
  CONSOLE_SCREEN_BUFFER_INFO buf_info;

  GetConsoleScreenBufferInfo(hd, &buf_info);
  old_clr_attr = buf_info.wAttributes;

  try {
    hotel = new Hotel(this);

    for (;;) {
      SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

      std::string cmd;
      std::cin >> cmd;

      if (cmd == "in") {
        hotel->checkIn();
      }
      else if (cmd == "out") {
        hotel->checkOut();
      }
      else if (cmd == "on") {
        int temp_init;
        std::cin >> temp_init;
        hotel->turnOn(temp_init);
      }
      else if (cmd == "off") {
        hotel->turnOff();
      }
      else if (cmd == "tem") {
        int temp;
        std::cin >> temp;
        hotel->setTemp(temp);
      }
      else if (cmd == "stt") {
        hotel->getState();
      }
      else if (cmd == "bil") {
        hotel->getBilling();
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
