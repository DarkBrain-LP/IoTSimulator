//
// Created by ManU_LP on 10/6/2023.
//
#include "iostream"
#include "Scheduler.h"
#include "thread"
#include "chrono"

Scheduler::Scheduler() {

}

Scheduler::~Scheduler() {

}

void Scheduler::schedule(Server server /*std::vector<Sensor> items*/) {
    while(true){
        for(int i = 0; i < server.getNbOfSensors(); ++i){
            if(server.isConsoleActive())
                server.consoleWrite(i);
            if(server.isLogActivate())
                server.fileWrite(i);
        }
        std::this_thread::sleep_for(std::chrono::seconds (DELAY/2));
    }
}
//
//std::vector<Sensor> Scheduler::LoadData(const std::vector<Sensor>& vectors) {
//
//    return std::vector<Sensor>();
//}
