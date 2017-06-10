/*
 * IMUSubsystem.h
 *
 *  Created on: May 27, 2017
 *  Author: Deep
 *  Description: IMU holds number of IMU sensors' objects and handles data related to them
 */

#ifndef SRC_IMUSUBSYSTEM_H_
#define SRC_IMUSUBSYSTEM_H_

#include "StandardCplusplus.h"
#include <vector>
#include "IMUSensor.h"
#include "shared/DataHandler.h"

class IMU {
    private:
        std::vector<IMUSensor*> sensors;
        const unsigned int sensor_total;

        // default values for x, y and z when sensor component stops working
        const long stop_value = -99999;

        DataHandler data_handler;

public:
    IMU(unsigned int num_sensors);

    ~IMU();

    // sensor_working() returns true if all sensors are working and false otherwise
    bool sensors_working();

    // serialPrint() prints data from component of the sensor to the Serial in JSON format
    void serial_print(unsigned int sensor, int component);

    // getSensorTotal() returns the number of sensors in the subsystem
    int get_sensor_total();

    // getX() returns the x value of the component from the particular system
    float get_x(unsigned int system, int component);

    // getY() returns the y value of the component from the particular system
    float get_y(unsigned int system, int component);

    // getZ() returns the z value of the component from the particular system
    float get_z(unsigned int system, int component);
};

#endif
