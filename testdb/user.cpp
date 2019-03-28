#include "user.h"
#include "querystring.h"

#include <iostream>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

User::User(QObject *parent): QObject(parent)
{
  db = QSqlDatabase::addDatabase("QODBC", "db");
  db.setDatabaseName("se2019");

  if (db.open()) {
    QSqlQueryModel *model = new QSqlQueryModel;
    /*
    model->setQuery("SELECT * FROM haha;", db);

    for (int i = 0; i < model->rowCount(); i++) {
      qDebug() << model->record(i);
    }
    */
  }
  else {
    throw "cannot open db";
  }
}

void User::regist()
{
  std::string name, pswd;
  std::cout << "Username: ";
  std::cin >> name;
  std::cout << "Password: ";
  std::cin >> pswd;

  QSqlQueryModel model;
  model.setQuery(QueryString::addNewUser(name, pswd), db);
  qDebug() << model.lastError();
  model.setQuery(QueryString::getLastID(), db);
  qDebug() << model.lastError();
  this->usr_id = model.record(0).value(0).toInt();

  std::cout << "user id: " << this->usr_id << std::endl;
}

void User::checkIn()
{
  QSqlQueryModel model;
//  model.setQuery(QueryString::findRoom(usr_id), db);
//  for (;;) {
//    // TODO
//  }
}

void User::checkOut()
{

}

void User::turnOn(int tem)
{

}

void User::turnOff()
{

}

void User::getTemp()
{

}

void User::setTemp(int tem)
{

}

void User::getState()
{

}

void User::getBilling()
{

}
