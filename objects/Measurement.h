#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>
#include "Date.h"

using namespace std;

class Measurement {
public:
    Measurement(const string& sensorID, const string& attributeID, const Date& timestamp, float value);

    const string& GetSensorID() const;
    const string& GetAttributeID() const;
    const Date& GetTimestamp() const;
    float GetValue() const;

private:
    string SensorID;
    string AttributeID;
    Date Timestamp;
    float Value;
};

#endif // MEASUREMENT_H
