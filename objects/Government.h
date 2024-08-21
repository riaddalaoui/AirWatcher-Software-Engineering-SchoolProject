#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "User.h"

class Government : public User {
public:
    Government();
    Government(const string& userID, const string& password);
    ~Government();
};

#endif // GOVERNMENT_H
