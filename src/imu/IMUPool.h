/*
 * IMUSubsystem.h
 *
 *  Created on: May 27, 2017
 *  Author: Deep
 *  Description: IMU holds number of IMU sensors' objects and handles data related to them
 */

#ifndef SRC_IMUSUBSYSTEM_H_
#define SRC_IMUSUBSYSTEM_H_

#include "IMU.h"
#include "../shared/DataHandler.h"


class IMUPool {
private:
    const unsigned int sensor_total;

    IMU **sensors;
    DataHandler data_handler;

public:
    IMUPool(unsigned int num_sensors);

    ~IMUPool();

    // sensor_working() returns true if all sensors are working and false otherwise
    bool sensors_working();

    // serialPrint() prints data from component of the sensor to the Serial in JSON format
    void serial_print(unsigned int sensor, imu_comp component);

    // getSensorTotal() returns the number of sensors in the subsystem
    int getTotal();

    // getX() returns the x value of the component from the particular system
    float getX(unsigned int system, imu_comp component);

    // getY() returns the y value of the component from the particular system
    float getY(unsigned int system, imu_comp component);

    // getZ() returns the z value of the component from the particular system
    float getZ(unsigned int system, imu_comp component);

    IMU *operator[](int &index);
};

#endif
