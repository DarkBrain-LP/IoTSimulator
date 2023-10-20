//
// Created by ManU_LP on 10/6/2023.
//

#ifndef CODE_SENSOR_H
#define CODE_SENSOR_H


class Sensor {
private:
    float valSense;
    float aleaGenVal();
public:
    Sensor(/* args */);
    Sensor(const Sensor&);
    Sensor(float valRcv);
    virtual ~Sensor();
    float SendData();
};


#endif //CODE_SENSOR_H
