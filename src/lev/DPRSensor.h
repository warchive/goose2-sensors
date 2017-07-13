/*!
 * @author Deep Dhillon
 * @date July 12 2017
 * @brief DPR sensor for Levitation which signals if DPR is on or off
 */

#ifndef SENSORS_DPRSENSOR_H
#define SENSORS_DPRSENSOR_H


#include <shared/Sensor.h>

class DPRSensor : public Sensor{
    const uint8_t pin;
    const uint8_t MAX_READING = 1;
    const uint8_t MIN_READING = 0;

    int getRawDPR();
public:
    /*!
     * Single constructor creates a DPR sensor at pin specified
     * @param name is the name of the sensor to be displayed
     * @param pin is the analog pin it is attached to
     */
    DPRSensor(const String name, const uint8_t pin);

    /*!
     * Reads sensor data from the analog pin and returns scaled values
     * @return the scaled value
     */
    float read();
};


#endif //SENSORS_DPRSENSOR_H
