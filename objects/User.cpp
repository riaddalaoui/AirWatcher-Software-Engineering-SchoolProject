#include "User.h"

User::User() {}

User::User(const string& userID, const string& password)
    : UserID(userID), Password(password) {}

User::~User() {}

string User::GetUserID() const {
    return UserID;
}

void User::SetUserID(const string& userID) {
    UserID = userID;
}

string User::GetPassword() const {
    return Password;
}

void User::SetPassword(const string& password) {
    Password = password;
}
