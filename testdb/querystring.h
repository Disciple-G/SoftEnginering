#ifndef QUERYSTRING_H
#define QUERYSTRING_H

#include <string>

class QString;

class QueryString {
public:
  static QString addNewUser(std::string name, std::string pswd);

  static QString getLastID();

  static QString findRoom(int usr_id);

  static QString getRoom(int usr_id);

  static QString setTemp(int room_id, int temp);

  static QString getState(int room_id);
};

#endif // QUERYSTRING_H
