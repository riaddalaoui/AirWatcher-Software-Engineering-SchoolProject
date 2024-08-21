#include "Services.h"
#include <cmath>  // Pour les fonctions mathématiques
#include <iostream>  // Pour les entrées et sorties (si nécessaire)
#include <vector>  // Pour utiliser les vecteurs
#include <set>  // Pour utiliser les ensembles

// Placeholder includes for DAOs et autres dépendances
Services::Services() {}

Services::~Services() {}

bool Services::analyzeSensor(const string& sensorID) {
    // Placeholder code
    cout << "Analyzing sensor: " << sensorID << endl;
    return true;
}

int Services::compareSensor(const string& sensorID, Date debut, Date fin) {
    // Placeholder code
    cout << "Comparing sensor: " << sensorID << endl;
    return 0;
}

int Services::computeAQIMoment(float latitude, float longitude, int radius, const Date& moment) {
    // Implémentez la logique pour calculer l'AQI à un moment donné
    // Placeholder code
    cout << "Computing AQI for moment at (" << latitude << ", " << longitude << ") with radius " << radius << endl;
    return 0;
}

float Services::computeAQIPeriod(float latitude, float longitude, int radius, const Date& start, const Date& end) {
    SensorDAO sensorDAO;
    MeasurementsDAO measurementsDAO;

    if (start > end) {
        cout << "Invalid period." << endl;
        return -1;
    }
    if (radius < 0) {
        cout << "Invalid radius." << endl;
        return -1;
    }

    vector<Sensors> sensors = sensorDAO.sensorsCircle(latitude, longitude, radius);
    if (sensors.empty()) {
        cout << "No sensors found in the given radius." << endl;
        return -1;
    }

    float totalAQI = 0;
    int count = 0;

    for (Sensors sensor : sensors) {
        vector<Measurement> measurements = measurementsDAO.measurementsOfSensorInPeriod(sensor.GetSensorID(), start, end);
        //calculer la moyenne de l'AQI pour chaque capteur dans la zone donnée
        if (!measurements.empty()) {
            totalAQI += measurementsDAO.AQIfromMeasurement(measurements);
            count++;   
        }
    }

    if (count == 0) {
        cout << "No measurements found in the given period." << endl;
        return -1;
    }
    float averageAQI = totalAQI / (float)count;
    cout << "Total AQI: " << totalAQI << ", N° of sensors:" << count << ", Average AQI in the area: " << averageAQI << endl;
    return averageAQI;
}

int Services::measureImprovement(Cleaner cleaner, const Date& start, const Date& stop) {
    // Placeholder code
    cout << "Measuring Improvement of cleaner : " << cleaner.GetCleanerID() << endl;
    return true;   
    }

float Services::measureAreaEffect(const string& cleanerID) {
    CleanerDAO cDAO = CleanerDAO();
    Cleaner cleaner = cDAO.findByID(cleanerID);
    SensorDAO sDAO = SensorDAO();
    vector<Sensors> listSensors= sDAO.rankedSensors(cleaner.GetLatitude(),cleaner.GetLongitude());
    if(cleaner.GetCleanerID() !="null"){
        float distance = 0.0;
        MeasurementsDAO mDAO = MeasurementsDAO();
        int difference = mDAO.measureImprovement(listSensors[0],cleaner.GetTimestampStart(),cleaner.GetTimestampStop()); //on entre dans le while seulement si le cleaner fait effet
        printf("différence : %d \n",difference);

        int i=1;
        while (i<listSensors.size() && difference>0){
            difference=mDAO.measureImprovement(listSensors[i],cleaner.GetTimestampStart(),cleaner.GetTimestampStop());
            printf("différence : %d \n",difference);
            distance = sqrt(pow(cleaner.GetLatitude() - listSensors[i].GetLatitude(), 2) + pow(cleaner.GetLongitude() - listSensors[i].GetLongitude(), 2));
            printf("distance : %f \n",distance);
            i++;
        }
        printf("Estimation du rayon maximum d'effet du cleaner : %f \n",distance);
        return distance;
    }else{
        printf("Mauvais ID \n");
        return 0.0;
    }
}



int Services::computeAQIPoint(float latitude, float longitude, const Date& moment) {
    // Implémentez la logique pour calculer l'AQI à un point spécifique
    // Placeholder code
    cout << "Computing AQI for point at (" << latitude << ", " << longitude << ") at moment" << endl;
    return 0;
}
