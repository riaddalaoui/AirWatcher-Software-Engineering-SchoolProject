#include "SensorDAO.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

SensorDAO::SensorDAO() {
    loadSensorsFromCSV("dataset/sensors.csv");
}

SensorDAO::~SensorDAO() {
}

void SensorDAO::loadSensorsFromCSV(const string& filePath) {
    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string id, latStr, lonStr;
        getline(ss, id, ';');
        getline(ss, latStr, ';');
        getline(ss, lonStr, ';');

        float latitude = stof(latStr);
        float longitude = stof(lonStr);

        Sensors sensor(id, latitude, longitude);
        sensors.push_back(sensor);
    }
    file.close();
}

vector<Sensors> SensorDAO::allSensors() {
    return sensors;
}

vector<Sensors> SensorDAO::sensorsCircle(float latitude, float longitude, int radius) {
    vector<Sensors> result;
    std::cout << "members of sensor list kept : " << std::endl ;
    for (Sensors sensor : sensors) {

        float sensorLatitude = sensor.GetLatitude();
        float sensorLongitude = sensor.GetLongitude();

        float distance = sqrt(pow(sensorLatitude - latitude, 2) + pow(sensorLongitude - longitude, 2));
        if (distance <= radius) {
            result.push_back(sensor);
            std::cout << sensor.GetSensorID() << std::endl;
        }
    }
    return result;
}

vector<Sensors> SensorDAO::rankedSensors(float latitude, float longitude) {
    vector<pair<Sensors, float>> distanceSensors;

    for (Sensors sensor : sensors) {
        float sensorLat = sensor.GetLatitude();
        float sensorLon = sensor.GetLongitude();
        float distance = sqrt(pow(sensorLat - latitude, 2) + pow(sensorLon - longitude, 2)); 
        distanceSensors.push_back(make_pair(sensor, distance));
    }

    sort(distanceSensors.begin(), distanceSensors.end(), [](const pair<Sensors, float>& a, const pair<Sensors, float>& b) {
        return a.second < b.second;
    });
    /*    for (pair<Sensors, float> ligne : distanceSensors){
        cout<<ligne.second<<endl;
    }
    */

    vector<Sensors> sortedSensors;
   
    for (pair<Sensors, float> pair : distanceSensors) {
        sortedSensors.push_back(pair.first);
    }
    
    return sortedSensors;
}

Sensors SensorDAO::findByID(const string & sensorID){
    for(Sensors sensor : sensors){
        if(sensor.GetSensorID()==sensorID){
            return sensor;
        }
    }
    return Sensors("null",0.0,0.0);
}

