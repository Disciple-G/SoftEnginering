#include "hotel.h"

#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QDebug>

Hotel::Hotel(QObject *parent): QObject(parent)
{
  db = QSqlDatabase::addDatabase("QODBC", "db");
  db.setDatabaseName("se2019");

  if (db.open()) {
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM haha;", db);

    for (int i = 0; i < model->rowCount(); i++) {
      qDebug() << model->record(i);
    }
  }
  else {
    throw "cannot open db";
  }
}

void Hotel::checkIn()
{

}

void Hotel::checkOut()
{

}

void Hotel::turnOn(int tem)
{

}

void Hotel::turnOff()
{

}

void Hotel::getTemp()
{

}

void Hotel::setTemp(int tem)
{

}

void Hotel::getState()
{

}

void Hotel::getBilling()
{

}

void Hotel::addNewUser()
{
  QSqlQueryModel *model = new QSqlQueryModel;
}
