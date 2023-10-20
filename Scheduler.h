//
// Created by ManU_LP on 10/6/2023.
//

#ifndef CODE_SCHEDULER_H
#define CODE_SCHEDULER_H

#include "Sensor.h"
#include "Server.h"
#include <vector>

class Scheduler {
public:
    Scheduler(/* args */);
    ~Scheduler();
//    std::vector<Sensor> LoadData();
    void schedule(Server server/*std::vector<Sensor> items*/);
private:
    int const DELAY = 60;
};


#endif //CODE_SCHEDULER_H
