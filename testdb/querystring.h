#ifndef QUERYSTRING_H
#define QUERYSTRING_H

class QString;

class QueryString {
public:
  static QString addNewUser(QString name, QString pswd);

  static QString findRoom();

  static QString setTemp(int room_id, int temp);

  static QString getState(int room_id);
};

#endif // QUERYSTRING_H
