#ifndef HOTEL_H
#define HOTEL_H

#include <QObject>
#include <QSqlDatabase>


class Hotel : public QObject
{
  Q_OBJECT
public:
  explicit Hotel(QObject *parent = nullptr);

  void checkIn();
  void checkOut();
  void turnOn(int tem);
  void turnOff();
  void getTemp();
  void setTemp(int tem);
  void getState();
  void getBilling();

private:
  QSqlDatabase db;

  void addNewUser();
};

#endif // HOTEL_H
