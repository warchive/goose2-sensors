/*
 * IMUSensor.h
 *
 *  Created on: May 24, 2017
 *  Author: Deep Dhillon
 *  Description: Declaration and documentation of IMUsensor class. This class encompasses all the components and
 *  			 is used to get values for different components.
 */

#ifndef IMUSensor_H
#define IMUSensor_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <SparkFunLSM9DS1.h>

#include "imu/imu_components/IMUAccel.h"
#include "imu/imu_components/IMUComponent.h"
#include "imu/imu_components/IMUGyro.h"
#include "imu/imu_components/IMUMag.h"

// constants
static const int GYRO = 0;
static const int ACCEL = 1;
static const int MAG = 2;

class IMUSensor {
private:
    LSM9DS1 imu;

    IMUComponent *gyro;
    IMUComponent *accel;
    IMUComponent *mag;

    // getComponent() returns the component based on what the parameter is
    IMUComponent *getComponent(int comp);

public:
    IMUSensor();

    ~IMUSensor();

    // reads the sensor and updates x, y and z values. It returns true if the read was successful
    // and false otherwise
    bool read(int comp);

    // isStarted() returns true if IMU sensor has started and false otherwise
    bool isStarted();

    // setupGyro() specifies the settings for the gyroscope.
    // * scale sets the full-scale range of the gyroscope. scale can be set to either 245, 500, or 2000
    // * sampleRatesets the output data rate (ODR) of the gyro
    //   sampleRate can be set between 1-6
    // 	 1 = 14.9    4 = 238
    //   2 = 59.5    5 = 476
    //   3 = 119     6 = 952
    // * flipX, flipY, and flipZ are booleans that can automatically switch the positive/negative
    //   orientation of the three gyro axes.
    void setupGyro(int scale = 245, int sampleRate = 3, bool flipX = false, bool flipY = false, bool flipZ = false);


    // setupAccel() specifies the settings for the accelerometer.
    // * scale sets the full-scale range of accelerometer. The scale can be 2, 4, 8 or 16
    // * sampleRate sets the output data rate of the accelerometer. If Gyroscope is running,
    //   the sample rate is same as gyroscope. Same rate can be be 1-6:
    //   1 = 10 Hz    4 = 238 Hz
    //   2 = 50 Hz    5 = 476 Hz
    //   3 = 119 Hz   6 = 952 Hz
    void setupAccel(int scale = 8, int sampleRate = 1);

    // setupMag() specifies the settings for the magnetometer.
    // * scale sets the full-scale range of the magnetometer. Mag scale can be 4, 8, 12, or 16
    // * sampleRate sets the output data rate (ODR) of the magnetometer.
    //   mag data rate can be 0-7:
    //   0 = 0.625 Hz  4 = 10 Hz
    //   1 = 1.25 Hz   5 = 20 Hz
    //   2 = 2.5 Hz    6 = 40 Hz
    //   3 = 5 Hz      7 = 80 Hz
    // * tempComp enables or disables temperature compensation of the magnetometer.
    // * operatingMode sets the operating mode of the magnetometer. operatingMode can be 0-2:
    //   0 = continuous conversion
    //   1 = single-conversion
    //   2 = power down
    void setupMag(int scale = 12, int sampleRate = 5, bool tempComp = false, int operatingMode = 0);

    // getX() returns the x value of the component
    float getX(int comp);

    // getY() returns the y value of the component
    float getY(int comp);

    // getZ() returns the z value of the component
    float getZ(int comp);
};

#endif
