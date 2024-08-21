#include "Provider.h"

Provider::Provider() {}

Provider::Provider(const string& userID, const string& password, const vector<string>& cleaner)
    : User(userID, password), Cleaner(cleaner) {}

Provider::~Provider() {}

vector<string> Provider::GetCleaner() const {
    return Cleaner;
}

void Provider::SetCleaner(const vector<string>& cleaner) {
    Cleaner = cleaner;
}
