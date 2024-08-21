#ifndef SENSORS_DAO_H
#define SENSORS_DAO_H

#include <vector>
#include <string>
#include <iostream>
#include "Sensors.h"

using namespace std;

class SensorDAO {
public:
    SensorDAO();
    ~SensorDAO();

    void loadSensorsFromCSV(const string& filePath);
    vector<Sensors> allSensors();
    vector<Sensors> sensorsCircle(float latitude, float longitude, int radius);
    vector<Sensors> rankedSensors(float latitude, float longitude);
    Sensors findByID(const string & sensorID);

private:
    vector<Sensors> sensors;
};

#endif // SENSORS_DAO_H
