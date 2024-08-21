#ifndef SERVICES_H
#define SERVICES_H

#include <string>
#include "Cleaner.h"
#include "Sensors.h"
#include "Date.h"
#include "Measurement.h"
#include "SensorDAO.h"
#include "CleanerDAO.h"
#include "IndividualDAO.h"
#include "AttributeDAO.h"
#include "MeasurementsDAO.h"
using namespace std;

class Services {
public:
    Services();
    ~Services();

    bool analyzeSensor(const string& sensorID);
    int compareSensor(const string& sensorID, Date debut, Date fin);
    int computeAQIMoment(float latitude, float longitude, int radius, const Date& moment);
    float computeAQIPeriod(float latitude, float longitude, int radius, const Date& start, const Date& end);
    int measureImprovement(Cleaner cleaner, const Date& start, const Date& end);
    float measureAreaEffect(const string& cleanerID);
    int computeAQIPoint(float latitude, float longitude, const Date& moment);
};

#endif // SERVICES_H
