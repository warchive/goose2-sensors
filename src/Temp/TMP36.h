//
// Created by Deep on 2017-06-28.
// Description: Provides library to measures temperature based on TMP36 temperature sensor
//

#ifndef SENSORS_TMP36_H
#define SENSORS_TMP36_H

#include <Arduino.h>
#include <shared/DataHandler.h>

class TMP36 {
    const String name;
    const uint8_t io_pin;
    DataHandler handler;

public:
    TMP36(const String name, const uint8_t io_pin);

    // serialPrint() prints temp data to the Serial
    void serialPrint();

    // getTemp() returns the updated temperature
    float getTemp() const;
};


#endif //SENSORS_TMP36_H
