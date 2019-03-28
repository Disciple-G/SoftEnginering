#include "querystring.h"

#include <QString>
#include <QDebug>

QString QueryString::addNewUser(std::string name, std::string pswd)
{
  std::string res = "INSERT INTO usr VALUES (NULL, '" + name + "', '" + pswd + "');";
  qDebug() << res.c_str();
  return QString(res.c_str());
}

QString QueryString::getLastID()
{
  return QString("SELECT last_insert_id();");
}
