#ifndef PROVIDER_H
#define PROVIDER_H

#include <vector>
#include <string>
#include "User.h"

using namespace std;

class Provider : public User {
public:
    Provider();
    Provider(const string& userID, const string& password, const vector<string>& cleaner);
    ~Provider();

    vector<string> GetCleaner() const;
    void SetCleaner(const vector<string>& cleaner);

private:
    vector<string> Cleaner;
};

#endif // PROVIDER_H
