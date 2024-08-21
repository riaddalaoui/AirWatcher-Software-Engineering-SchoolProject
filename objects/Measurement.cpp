#include "Measurement.h"

Measurement::Measurement(const string& sensorID, const string& attributeID, const Date& timestamp, float value)
    : SensorID(sensorID), AttributeID(attributeID), Timestamp(timestamp), Value(value) {}

const string& Measurement::GetSensorID() const {
    return SensorID;
}

const string& Measurement::GetAttributeID() const {
    return AttributeID;
}

const Date& Measurement::GetTimestamp() const {
    return Timestamp;
}

float Measurement::GetValue() const {
    return Value;
}
