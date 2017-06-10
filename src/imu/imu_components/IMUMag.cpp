/*
 * IMUMag.cpp
 *
 *  Created on: May 25, 2017
 *      Author: Deep6
 */

#include "../imu_components/IMUMag.h"

IMUMag::IMUMag(LSM9DS1 &imu) : imu{imu} {}

bool IMUMag::read() {
    if (imu.magAvailable()) {
        imu.readMag();
        return true;
    }

    return false;
}

float IMUMag::getX() {
    x = imu.calcMag(imu.mx);
    return x;
}

float IMUMag::getY() {
    y = imu.calcMag(imu.mx);
    return y;
}

float IMUMag::getZ() {
    z = imu.calcMag(imu.mz);
    return y;
}
