#ifndef CLEANER_DAO_H
#define CLEANER_DAO_H

#include <vector>
#include <string>
#include <iostream>
#include "Cleaner.h"

using namespace std;

class CleanerDAO {
public:
    CleanerDAO();
    ~CleanerDAO();

    void loadCleanersFromCSV(const string& filePath);
    vector<Cleaner> allCleaners();
    Cleaner findByID(const string& cleanerID);

private:
    vector<Cleaner> cleaners;
};

#endif // CLEANER_DAO_H
