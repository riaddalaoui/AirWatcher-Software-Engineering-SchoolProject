#ifndef MEASUREMENTSDAO_H
#define MEASUREMENTSDAO_H

#include <vector>
#include <string>
#include "SensorDAO.h"
#include "Measurement.h"
#include "Date.h"
#include "Sensors.h"

using namespace std;

class MeasurementsDAO {
public:
    MeasurementsDAO();
    ~MeasurementsDAO();

    void loadMeasurementsFromCSV(const string& filePath);
    bool isWithinRadius(float, float, float, float, int);
    vector<Measurement> measurementsInCircleAtMoment(float, float, int, const Date&);
    vector<Measurement> measurementsOfSensorInPeriod(const string& sensorID, const Date& start, const Date& end);
    int AQIfromMeasurement(vector<Measurement>);
    int measureImprovement(const Sensors& sensor, const Date& start, const Date& stop);

private:
    vector<Measurement> measurements;
    string measurementsFilePath;
    string sensorsFilePath;

    bool isWithinPeriod(const Date& date, const Date& start, const Date& end);
};

#endif // MEASUREMENTSDAO_H
