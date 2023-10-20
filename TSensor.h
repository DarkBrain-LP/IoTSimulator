//
// Created by ManU_LP on 10/20/2023.
//

#ifndef CODE_TSENSOR_H
#define CODE_TSENSOR_H


template<class T> class TSensor {
private:
    T valSense;
    T aleaGenVal();
public:
    TSensor(/* args */);
    TSensor(const TSensor&);
    TSensor(T valRcv);
    virtual ~TSensor();
    T SendData();
};


#endif //CODE_TSENSOR_H
