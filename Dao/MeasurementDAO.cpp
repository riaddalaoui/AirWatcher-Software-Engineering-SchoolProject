#include "MeasurementsDAO.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include "Measurement.h"
#include "Sensors.h"

MeasurementsDAO::MeasurementsDAO() {
    loadMeasurementsFromCSV("dataset/measurements.csv");
}

MeasurementsDAO::~MeasurementsDAO() {}

void MeasurementsDAO::loadMeasurementsFromCSV(const string& filePath) {
    measurementsFilePath = filePath;
    vector<Measurement> result;
    ifstream measurementsFile(measurementsFilePath);
    string line;

    while (getline(measurementsFile, line)) {
        stringstream ss(line);
        string timestampStr, id, attributeID, valueStr;
        getline(ss, timestampStr, ';');
        getline(ss, id, ';');
        getline(ss, attributeID, ';');
        getline(ss, valueStr, ';');
        // Parse timestamp
        int year, month, day, hour, minute, second;
        sscanf(timestampStr.c_str(), "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
        Date timestamp(year, month, day, hour, minute, second);
        // Parse value
        float value = stof(valueStr);
        Measurement measurement(id, attributeID, timestamp, value);
        result.push_back(measurement);
    }
    measurementsFile.close();
    measurements = result;
}

bool MeasurementsDAO::isWithinRadius(float lat1, float lon1, float lat2, float lon2, int radius) {
    // Calcul de la distance entre deux points géographiques (approximatif)
    float distance = sqrt(pow(lat2 - lat1, 2) + pow(lon2 - lon1, 2)); 
    return distance <= radius;
}

bool MeasurementsDAO::isWithinPeriod(const Date& date, const Date& start, const Date& end) {
    return (date >= start && date <= end);
}

vector<Measurement> MeasurementsDAO::measurementsOfSensorInPeriod(const string& sensorID, const Date& start, const Date& end) {
    vector<Measurement> result;
    MeasurementsDAO mDAO = MeasurementsDAO();
    for(Measurement measurement : measurements){
        if (measurement.GetSensorID() == sensorID && mDAO.isWithinPeriod(measurement.GetTimestamp(),start,end)) {
            result.push_back(measurement);
        }
    }
    return result;
}

vector<Measurement> MeasurementsDAO::measurementsInCircleAtMoment(float latitude, float longitude, int radius, const Date& moment) {
    vector<Measurement> result;
    SensorDAO sDAO = SensorDAO();
    float distance;
    Sensors sensor;
    for (Measurement measurement : measurements){
        Sensors sensor = sDAO.findByID(measurement.GetSensorID());
        if(sensor.GetSensorID()!="null" && measurement.GetTimestamp().day == moment.day && isWithinRadius(sensor.GetLatitude(),sensor.GetLongitude(),latitude,longitude,radius)==true){
            result.push_back(measurement);
        }
    }
    return result;
}


int MeasurementsDAO::AQIfromMeasurement(vector<Measurement> vM){
    vector<Measurement>::iterator i;
    //calcul des valeurs moyennes pour chaque type de mesure
    float t[4] = {0, 0, 0, 0};
    int n[4] = {0,0,0,0};
    for(i=vM.begin(); i!=vM.end(); ++i){
        cout << (*i).GetSensorID() << endl; /// trace
        string att = (*i).GetAttributeID();
        float val = (*i).GetValue();
        if(att=="O3") {
                t[0] += val;
                n[0]++;
        } else if(att=="NO2"){
                (t[1])+=val;
                ++n[1];
          } else if (att=="SO2"){
                (t[2])+=val;
                ++n[2];
           } else if(att=="PM10"){
                (t[3])+=val;
                ++n[3];
           }
    }
    int j;
    for (j=0; j<4;++j){
        if (n[j]!=0) {t[j]/=n[j];}
    }
    
    //calcul de la valeur de l'AQI
    int atmo;
    int aqi=0;
    for (j=0 ; j<4;++j){
        atmo=0;
        float val = t[j];
        if(j==0) {
                if(val<30){atmo=1;}
                else if(val<55){atmo=2;}
                else if(val<80){atmo=3;}
                else if(val<105){atmo=4;}
                else if(val<130){atmo=5;}
                else if(val<150){atmo=6;}
                else if(val<180){atmo=7;}
                else if(val<210){atmo=8;}
                else if(val<240){atmo=9;}
                else {atmo=10;}
        } else if(j==1){   
                if(val<30){atmo=1;}
                else if(val<55){atmo=2;}
                else if(val<85){atmo=3;}
                else if(val<110){atmo=4;}
                else if(val<135){atmo=5;}
                else if(val<165){atmo=6;}
                else if(val<200){atmo=7;}
                else if(val<275){atmo=8;}
                else if(val<400){atmo=9;}
                else {atmo=10;}
          } else if (j==2){
                if(val<40){atmo=1;}
                else if(val<80){atmo=2;}
                else if(val<120){atmo=3;}
                else if(val<160){atmo=4;}
                else if(val<200){atmo=5;}
                else if(val<250){atmo=6;}
                else if(val<300){atmo=7;}
                else if(val<400){atmo=8;}
                else if(val<500){atmo=9;}
                else {atmo=10;}
           } else if(j==3){
                if(val<7){atmo=1;}
                else if(val<14){atmo=2;}
                else if(val<21){atmo=3;}
                else if(val<28){atmo=4;}
                else if(val<35){atmo=5;}
                else if(val<42){atmo=6;}
                else if(val<50){atmo=7;}
                else if(val<65){atmo=8;}
                else if(val<80){atmo=9;}
                else {atmo=10;}
           }
        //cout<<atmo<<endl;
        if (atmo>aqi){aqi=atmo;}
    }
    cout<<aqi<<endl;
    return aqi;
}

int MeasurementsDAO::measureImprovement(const Sensors& sensor, const Date& start, const Date& stop) {
    printf("dans le bon measureImprovement\n");
    vector<Measurement> measurementBefore = measurementsOfSensorInPeriod(sensor.GetSensorID(),Date(start.year,start.month,start.day, start.hour-1, 0,0),Date(start.year,start.month,start.day, start.hour+1, 0,0)); 
    vector<Measurement> measurementAfter = measurementsOfSensorInPeriod(sensor.GetSensorID(),Date(stop.year,stop.month,stop.day, stop.hour-1, 0,0),Date(stop.year,stop.month,stop.day, stop.hour+1, 0,0)); 

    int AQIBefore = AQIfromMeasurement(measurementBefore);
    int AQIAfter = AQIfromMeasurement(measurementAfter);
    int improvement = AQIBefore-AQIAfter;
    printf("improvement : %d\n",improvement);
    return improvement;
}