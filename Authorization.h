#ifndef AUTHORIZATION_H_
#define AUTHORIZATION_H_
// авторизация
#include "RunApplication.h"
extern size_t userSize;
extern std::string userStatus[1];
extern std::string* loginArr;
extern std::string* passArr;
extern std::string* statusArr;
extern int currentId;

bool Login();


#endif // AUTHORIZATION_H_