#ifndef AUTHORIZATION_H_
#define AUTHORIZATION_H_

#include "Header.h"

struct User {
    std::string login;
    std::string password;
    std::string status;
};

extern std::vector<User> users;
extern std::string currentUserStatus;
bool Login();
void RegisterUser();

#endif