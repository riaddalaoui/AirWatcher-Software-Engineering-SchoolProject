#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
#include "User.h"
#include "Sensors.h"

using namespace std;

class Individual : public User {
public:
    Individual();
    Individual(const string& userID, const string& password, int points, bool reliable, const vector<Sensors>& sensorsList);
    ~Individual();

    int GetPoints() const;
    void SetPoints(int points);

    bool GetReliable() const;
    void SetReliable(bool reliable);

    vector<Sensors> GetSensorsList() const;
    void SetSensorsList(const vector<Sensors>& sensorsList);

private:
    int Points;
    bool Reliable;
    vector<Sensors> SensorsList;
};

#endif // INDIVIDUAL_H
