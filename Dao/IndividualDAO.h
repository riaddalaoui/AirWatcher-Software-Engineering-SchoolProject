#ifndef INDIVIDUALDAO_H
#define INDIVIDUALDAO_H

#include <string>

using namespace std;

class IndividualDAO {
public:
    IndividualDAO();
    ~IndividualDAO();

    void markMalicious(const string& userID);
    void addPoint(const string& userID);
};

#endif // INDIVIDUALDAO_H
