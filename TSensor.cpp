//
// Created by ManU_LP on 10/20/2023.
//

#include "TSensor.h"
#include <cstdlib>
#include <ctime>

template<class T>
TSensor<T>:: TSensor(/* args */): valSense(aleaGenVal())
{
    srand(static_cast<unsigned>(time(0)));
};
template<class T>
TSensor<T> ::TSensor(const TSensor & sensor): valSense(sensor.valSense)
{
    srand(static_cast<unsigned>(time(0)));
};

template<class T>
TSensor<T>:: TSensor(T a) : valSense(a)
{
    srand(static_cast<unsigned>(time(0)));
};

template<class T>
TSensor<T>:: ~TSensor(){};

template<class T>
T TSensor<T>:: SendData(){
    T actualValue = valSense;
    valSense = aleaGenVal();
    return actualValue;
}

template<class T>
T TSensor<T>:: aleaGenVal(){
//    srand(time(0));
    return static_cast<T>(rand());
}