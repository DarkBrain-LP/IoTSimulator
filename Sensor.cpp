//
// Created by ManU_LP on 10/6/2023.
//

#include "Sensor.h"
#include <cstdlib>
#include <ctime>

Sensor:: Sensor(/* args */): valSense(aleaGenVal())
{
    srand(static_cast<unsigned>(time(0)));
};

Sensor::Sensor(const Sensor & sensor): valSense(sensor.valSense)
{
    srand(static_cast<unsigned>(time(0)));
};

Sensor:: Sensor(float a) : valSense(a)
{
    srand(static_cast<unsigned>(time(0)));
};

Sensor:: ~Sensor(){};

float Sensor:: SendData(){
    int actualValue = valSense;
    valSense = aleaGenVal();
    return actualValue;
}

float Sensor:: aleaGenVal(){
//    srand(time(0));
    return static_cast<float>(rand());
}

