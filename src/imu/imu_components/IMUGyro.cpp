/*
 * IMUGyro.cpp
 *
 *  Created on: May 24, 2017
 *  Author: Deep Dhillon
 *  Description: Implementation of IMUGyro class
 */

#include "../imu_components/IMUGyro.h"

IMUGyro::IMUGyro(LSM9DS1 &imu) : imu{imu} {}

bool IMUGyro::read() {
    if (imu.gyroAvailable()) {
        imu.readGyro();
        return true;
    }

    return false;
}

float IMUGyro::getX() {
    x = imu.calcGyro(imu.gx);
    return x;
}

float IMUGyro::getY() {
    y = imu.calcGyro(imu.gy);
    return y;
}

float IMUGyro::getZ() {
    z = imu.calcGyro(imu.gz);
    return z;
}
