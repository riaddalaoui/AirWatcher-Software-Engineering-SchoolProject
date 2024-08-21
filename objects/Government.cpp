#include "Government.h"

Government::Government() {}

Government::Government(const string& userID, const string& password)
    : User(userID, password) {}

Government::~Government() {}
