/*
 * IMUAccel.h
 *
 *  Created on: May 24, 2017
 *  Author: Deep Dhillon
 *  Description: Declaration and documentation of IMUAccel class. This class is in charge of handling accelerometer
 *  			 data from the IMU Sensor
 */

#ifndef SRC_IMU_COMPONENTS_IMUACCEL_H_
#define SRC_IMU_COMPONENTS_IMUACCEL_H_

#include "../imu_components/IMUComponent.h"

class IMUAccel : public IMUComponent {
private:
    LSM9DS1 &imu;

public:
    IMUAccel(LSM9DS1 &imu);

    bool read() override;

    float getX() override;

    float getY() override;

    float getZ() override;
};

#endif
