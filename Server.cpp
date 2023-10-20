//
// Created by ManU_LP on 10/6/2023.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <string>
#include "Server.h"

#define HUMIDITE "./donnees/capteur_humidite.txt"
#define TEMPERATURE "./donnees/capteur_temperature.txt"
#define LUMIERE "./donnees/capteur_lumiere.txt"
#define SONORE "./donnees/capteur_sonore.txt"

class ofstream;

void Server::WriteFile(const std::string &filename) {
    std::ofstream outputFile(filename, std::ios::app);
        time_t dateEcriture ;
        char* dt ;
        std::string s ;
        dateEcriture = time(0);
        dt = ctime(&dateEcriture);
        s = dt;
        s.erase(remove_if(s.begin(), s.end(), ::isspace),
                s.end());
        if (outputFile.is_open())
        {
            outputFile << "Date : " << dt << "\n";
            outputFile << "Humidité: " << captHumidite << "\n";
            outputFile << "Lumière: " << captLumiere << "\n";
            outputFile << "Son: " << captSonore << "\n";
            outputFile << "Température: " << captTemperature << "\n";
            outputFile.close();
        }
        else
        {
            std::cerr << "écriture impossible." << std::endl;
        }
}

Server::Server() : sensors(), logAdctivation(true), consolActivation(true), nbrOfSensors(0) {
}


Server::Server(const Server &toCopy)
: nbrOfSensors(toCopy.nbrOfSensors), consolActivation(toCopy.consolActivation), logAdctivation(toCopy.logAdctivation),
    sensors(toCopy.sensors)
{
}

Server &Server::operator=(const Server &server)
{
    nbrOfSensors = server.nbrOfSensors;
    consolActivation = server.consolActivation;
    logAdctivation = server.logAdctivation;
    sensors = std::vector<Sensor*>(server.sensors);
        return *this;
}

Server::Server(int nbrOfSensors, bool consolActivation, bool logActivation)
    : nbrOfSensors(nbrOfSensors), consolActivation(consolActivation), logAdctivation(logActivation)
{
}

Server::Server(std::vector<Sensor*> sensors)
        : nbrOfSensors(sensors.size()), consolActivation(true),
        logAdctivation(true), sensors(sensors)
{

}

void Server::consoleWrite(int dataSens)
{
    std::cout << getDate() << ": " << typeid(*sensors[dataSens]).name() << " : " << sensors[dataSens]->SendData() << std::endl;
}

void Server::fileWrite(int dataSens) {
    std::ofstream outputFile(logFile, std::ios::app);
    if (outputFile.is_open())
    {
        outputFile << getDate()  << " " << typeid(*sensors[dataSens]).name() << " " << sensors[dataSens]->SendData() << "\n";
        outputFile.close();
    }
    else
    {
        std::cerr << "écriture impossible." << std::endl;
    }
}

void Server::WriteFile(int sensorNum) {
    std::ofstream outputFile(logFile, std::ios::app);

    if (outputFile.is_open())
    {
        outputFile << getDate() << " ";
        outputFile << typeid(sensors[sensorNum]).name() << sensors[sensorNum]->SendData() << " " << "\n";
        outputFile.close();
    }
    else
    {
        std::cerr << "écriture impossible." << std::endl;
    }
}

std::string Server::getDate() {
    time_t dateEcriture ;
    char* dt ;
    std::string s ;
    dateEcriture = time(0);
    dt = ctime(&dateEcriture);
    s = dt;
    s.erase(remove_if(s.begin(), s.end(), ::isspace),
            s.end());

    return s;
}

void Server::operator>>(int dataSens) {

}

void Server::operator>>(std::string dataSensToString) {

}

bool Server::isLogActivate() {
    return logAdctivation;
}

bool Server::isConsoleActive() {
    return consolActivation;
}

float Server::getNbOfSensors() {
    return nbrOfSensors;
}



