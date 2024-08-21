#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
protected:
    string UserID;
    string Password;

public:
    User();
    User(const string& userID, const string& password);
    virtual ~User();

    string GetUserID() const;
    void SetUserID(const string& userID);

    string GetPassword() const;
    void SetPassword(const string& password);
};

#endif // USER_H
