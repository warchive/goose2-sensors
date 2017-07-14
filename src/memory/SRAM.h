/*!
 * @author Deep Dhillon
 * @date July 14 2017
 * @brief This Library gives information about amount of free SRAM
 *        available on arduino
 */

#ifndef SENSORS_SRAM_H
#define SENSORS_SRAM_H


#include <shared/Sensor.h>

class SRAM : public Sensor{
public:
    SRAM(const String name, const uint8_t freq);

    /*!
     * Calculates free SRAM and stores it to be printed later on
     * @return
     */
    float read();
};


#endif //SENSORS_SRAM_H
