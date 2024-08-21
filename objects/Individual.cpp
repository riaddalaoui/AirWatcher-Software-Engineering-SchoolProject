#include "Individual.h"

Individual::Individual() : Points(0), Reliable(true) {}

Individual::Individual(const string& userID, const string& password, int points, bool reliable, const vector<Sensors>& sensorsList)
    : User(userID, password), Points(points), Reliable(reliable), SensorsList(sensorsList) {}

Individual::~Individual() {}

int Individual::GetPoints() const {
    return Points;
}

void Individual::SetPoints(int points) {
    Points = points;
}

bool Individual::GetReliable() const {
    return Reliable;
}

void Individual::SetReliable(bool reliable) {
    Reliable = reliable;
}

vector<Sensors> Individual::GetSensorsList() const {
    return SensorsList;
}

void Individual::SetSensorsList(const vector<Sensors>& sensorsList) {
    SensorsList = sensorsList;
}
