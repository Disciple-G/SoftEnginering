#ifndef USER_H
#define USER_H

#include <QObject>
#include <QSqlDatabase>


class User : public QObject
{
  Q_OBJECT
public:
  explicit User(QObject *parent = nullptr);

  void regist();
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

  int usr_id;
  int room_id;
};

#endif // USER_H
