//
// Created by Deep on 2017-06-27.
//

#ifndef NEW_SENSORS_IMU_H
#define NEW_SENSORS_IMU_H


#include <SparkFunLSM9DS1.h>

enum imu_comp {
    GYRO = 0,
    ACCEL = 1,
    MAG = 2
};

class IMU {
    LSM9DS1 imu;
    const float error_val = -99999.00000;
public:
    IMU();

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
    void setupGyro(uint8_t scale = 245, uint8_t sampleRate = 3, uint8_t flipX = false,
                   uint8_t flipY = false, uint8_t flipZ = false);

    // setupAccel() specifies the settings for the accelerometer.
    // * scale sets the full-scale range of accelerometer. The scale can be 2, 4, 8 or 16
    // * sampleRate sets the output data rate of the accelerometer. If Gyroscope is running,
    //   the sample rate is same as gyroscope. Same rate can be be 1-6:
    //   1 = 10 Hz    4 = 238 Hz
    //   2 = 50 Hz    5 = 476 Hz
    //   3 = 119 Hz   6 = 952 Hz
    void setupAccel(uint8_t scale = 8, uint8_t sampleRate = 1);

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
    void setupMag(uint8_t scale = 12, uint8_t sampleRate = 5, uint8_t tempComp = false,
                  uint8_t operatingMode = 0);

    // getX() returns the x value of the component
    float getX(imu_comp comp);

    // getY() returns the y value of the component
    float getY(imu_comp comp);

    // getZ() returns the z value of the component
    float getZ(imu_comp comp);
};


#endif //NEW_SENSORS_IMU_H
