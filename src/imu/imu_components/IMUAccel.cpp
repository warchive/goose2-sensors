/*
 * IMUAccel.cpp
 *
 *  Created on: May 24, 2017
 *  Author: Deep Dhillon
 *  Description: Implementation of IMUAccel class
 */

#include "../imu_components/IMUAccel.h"


IMUAccel::IMUAccel(LSM9DS1 &imu) : imu{imu} {}


bool IMUAccel::read() {
    if (imu.accelAvailable()) {
        imu.readAccel();
        return true;
    }

    return false;
}


float IMUAccel::getX() {
    x = imu.calcAccel(imu.ax);
    return x;
}

float IMUAccel::getY() {
    y = imu.calcAccel(imu.ax);
    return y;
}

float IMUAccel::getZ() {
    z = imu.calcAccel(imu.az);
    return y;
}
