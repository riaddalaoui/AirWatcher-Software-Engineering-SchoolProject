#include "Cleaner.h"

Cleaner::Cleaner() : Latitude(0.0), Longitude(0.0), Timestamp_start(Date(0, 0, 0)), Timestamp_stop(Date(0, 0, 0)) {}

Cleaner::Cleaner(const string& cleanerID, float latitude, float longitude, const Date& start, const Date& stop)
    : CleanerID(cleanerID), Latitude(latitude), Longitude(longitude), Timestamp_start(start), Timestamp_stop(stop) {}

Cleaner::~Cleaner() {}

string Cleaner::GetCleanerID() const {
    return CleanerID;
}

void Cleaner::SetCleanerID(const string& cleanerID) {
    CleanerID = cleanerID;
}

float Cleaner::GetLatitude() const {
    return Latitude;
}

void Cleaner::SetLatitude(float latitude) {
    Latitude = latitude;
}

float Cleaner::GetLongitude() const {
    return Longitude;
}

void Cleaner::SetLongitude(float longitude) {
    Longitude = longitude;
}

Date Cleaner::GetTimestampStart() const {
    return Timestamp_start;
}

void Cleaner::SetTimestampStart(const Date& timestampStart) {
    Timestamp_start = timestampStart;
}

Date Cleaner::GetTimestampStop() const {
    return Timestamp_stop;
}

void Cleaner::SetTimestampStop(const Date& timestampStop) {
    Timestamp_stop = timestampStop;
}
