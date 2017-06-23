#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <Arduino.h>

class Color_Sensor{
public:
    Color_Sensor();
    ~Color_Sensor();

    int out1;
    int out2;
    int out3;
    int temp;
    int count;
    
    void get_limitOut1();
    void get_limitOut2();
    void get_limitOut3();
    void counter();
  

private:
    DataHandler data_handler;
    
};

#endif
