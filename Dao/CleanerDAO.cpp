#include "CleanerDAO.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

CleanerDAO::CleanerDAO() {
    loadCleanersFromCSV("dataset/cleaners.csv");
}

CleanerDAO::~CleanerDAO() {}

void CleanerDAO::loadCleanersFromCSV(const string& filePath) {
    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, latStr, lonStr;
        string startDay,startMonth,startYear,startHour,startMinute,startSecond;
        string stopDay,stopMonth,stopYear,stopHour,stopMinute,stopSecond;
        getline(ss, id, ';');
        getline(ss, latStr, ';');
        getline(ss, lonStr, ';');
        getline(ss, startYear, '-');
        getline(ss, startMonth, '-');
        getline(ss, startDay, ' ');
        getline(ss, startHour, ':');
        getline(ss, startMinute, ':');
        getline(ss, startSecond, ';');
        getline(ss, stopYear, '-');   
        getline(ss, stopMonth, '-');     
        getline(ss, stopDay, ' ');
        getline(ss, stopHour, ':');
        getline(ss, stopMinute, ':');
        getline(ss, stopSecond, ';');

        float latitude = stof(latStr);
        float longitude = stof(lonStr);
        Date start = Date(atoi(startYear.c_str()),atoi(startMonth.c_str()),atoi(startDay.c_str()),atoi(startHour.c_str()),atoi(startMinute.c_str()),atoi(startSecond.c_str()));
        Date stop = Date(atoi(stopYear.c_str()),atoi(stopMonth.c_str()),atoi(stopDay.c_str()),atoi(stopHour.c_str()),atoi(stopMinute.c_str()),atoi(stopSecond.c_str()));

        Cleaner cleaner = Cleaner(id, latitude, longitude,start,stop);
        cleaners.push_back(cleaner);
    }
    file.close();
}

vector<Cleaner> CleanerDAO::allCleaners() {
    return cleaners;
}

Cleaner CleanerDAO::findByID(const string& cleanerID){
    for(Cleaner cleaner : cleaners){
        if(cleaner.GetCleanerID()==cleanerID){
            return cleaner;
        }
    }
    return Cleaner("null",0,0,Date(0,0,0,0,0,0),Date(0,0,0,0,0,0));
}

