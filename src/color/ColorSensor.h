#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <shared/Sensor.h>

class ColorSensor : public Sensor{
    const uint8_t out1Pin;
    const uint8_t out2Pin;
    const uint8_t out3Pin;

    // limit() restricts the value to 0 and based on the bound
    uint8_t limit(const int value, const int bound);

public:
    ColorSensor(const String name, const uint8_t ou1Pin,
                const uint8_t out2Pin, const uint8_t out3Pin);
    uint8_t getOut1();
    uint8_t getOut2();
    uint8_t getOut3();
    float read();
};

#endif
