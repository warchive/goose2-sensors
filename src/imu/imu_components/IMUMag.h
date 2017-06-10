/*
 * IMUMag.h
 *
 *  Created on: May 25, 2017
 *  Author: Deep Dhillon
 *  Description: Declaration and documentation of IMUMag class. This class is in charge of handling Magnetometer
 *  			 data from the IMU Sensor
 */

#ifndef SRC_IMU_COMPONENTS_IMUMAG_H_
#define SRC_IMU_COMPONENTS_IMUMAG_H_

#include "../imu_components/IMUComponent.h"

class IMUMag : public IMUComponent {
private:
    LSM9DS1 &imu;

public:
    IMUMag(LSM9DS1 &imu);

    bool read() override;

    float getX() override;

    float getY() override;

    float getZ() override;
};

#endif
