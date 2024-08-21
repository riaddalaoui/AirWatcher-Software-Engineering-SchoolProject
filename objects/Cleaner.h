#ifndef CLEANER_H
#define CLEANER_H

#include <string>
#include "Date.h"

using namespace std;

class Cleaner {
public:
    Cleaner();
    Cleaner(const string& cleanerID, float latitude, float longitude, const Date& start, const Date& stop);
    ~Cleaner();

    string GetCleanerID() const;
    void SetCleanerID(const string& cleanerID);

    float GetLatitude() const;
    void SetLatitude(float latitude);

    float GetLongitude() const;
    void SetLongitude(float longitude);

    Date GetTimestampStart() const;
    void SetTimestampStart(const Date& timestampStart);

    Date GetTimestampStop() const;
    void SetTimestampStop(const Date& timestampStop);

private:
    string CleanerID;
    float Latitude;
    float Longitude;
    Date Timestamp_start;
    Date Timestamp_stop;
};

#endif // CLEANER_H
