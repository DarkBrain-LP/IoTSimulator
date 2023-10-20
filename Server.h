//
// Created by ManU_LP on 10/6/2023.
//

#ifndef CODE_SERVER_H
#define CODE_SERVER_H


#include <string>
#include <ostream>
#include <vector>
#include "Sensor.h"

class ostream;

class Server {
private:
    /* data */
    float captTemperature;
    float captHumidite;
    float captLumiere;
    float captSonore;

    int nbrOfSensors;
    bool consolActivation;
    bool logAdctivation;


    void WriteFile(const std::string& filename) ;
    void WriteFile(const int sensorNum) ;
    const std::string logFile = "../log.txt";
    std::string getDate();

protected:
    std::vector<Sensor*> sensors;
public:
    Server();
    Server(int nbrOfSensors, bool consolActivation, bool logActivation);
    Server(std::vector<Sensor*> sensors);
    Server(Server const& toCopy);
    ~Server() {}
    Server& operator=(Server const& server);

    float getNbOfSensors();
    bool isConsoleActive();
    bool isLogActivate();

    void operator>>(int dataSens);
    void operator>>(std::string dataSensToString);
    void DataRcv(int datSens);
    void consoleWrite(int dataSens);
    void fileWrite(int dataSens);

};


#endif //CODE_SERVER_H
