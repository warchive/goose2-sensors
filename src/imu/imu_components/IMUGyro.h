/*
 * IMUGyro.h
 *
 *  Created on: May 24, 2017
 *  Author: Deep Dhillon
 *  Description: Definition and documentation of IMUGyro class. This class handles the gyroscope data from
 *  			 the the IMU Sensor.
 */

#ifndef SRC_IMUGYRO_H_
#define SRC_IMUGYRO_H_

#include "../imu_components/IMUComponent.h"

class IMUGyro : public IMUComponent {
private:
    LSM9DS1 &imu;

public:
    IMUGyro(LSM9DS1 &imu);

    bool read() override;

    float getX() override;

    float getY() override;

    float getZ() override;
};

#endif
