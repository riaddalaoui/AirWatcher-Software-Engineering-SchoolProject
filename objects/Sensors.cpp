#include "Sensors.h"

Sensors::Sensors() : Latitude(0.0), Longitude(0.0) {}

Sensors::Sensors(const string& sensorID, float latitude, float longitude)
    : SensorID(sensorID), Latitude(latitude), Longitude(longitude) {}

Sensors::~Sensors() {}

string Sensors::GetSensorID() const {
    return SensorID;
}

void Sensors::SetSensorID(const string& sensorID) {
    SensorID = sensorID;
}

float Sensors::GetLatitude() const {
    return Latitude;
}

void Sensors::SetLatitude(float latitude) {
    Latitude = latitude;
}

float Sensors::GetLongitude() const {
    return Longitude;
}

void Sensors::SetLongitude(float longitude) {
    Longitude = longitude;
}
