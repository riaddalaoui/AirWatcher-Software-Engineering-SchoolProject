#ifndef SENSORS_H
#define SENSORS_H

#include <string>

using namespace std;

class Sensors {
public:
    Sensors();
    Sensors(const string& sensorID, float latitude, float longitude);
    ~Sensors();

    string GetSensorID() const;
    void SetSensorID(const string& sensorID);
    float GetLatitude() const;
    void SetLatitude(float latitude);
    float GetLongitude() const;
    void SetLongitude(float longitude);

private:
    string SensorID;
    float Latitude;
    float Longitude;
};

#endif // SENSORS_H
