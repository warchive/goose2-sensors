/*
 * IMUSensor.cpp
 *
 *  Created on: May 24, 2017
 *  Author: Deep Dhillon
 *  Description: Implementation of IMUSensor class
 */

#include "IMUSensor.h"

// SDO_XM and SDO_G are both pulled high, so our addresses are:
#define LSM9DS1_M   0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG  0x6B // Would be 0x6A if SDO_AG is LOW

IMUSensor::~IMUSensor() {
    delete gyro;
    delete accel;
    delete mag;
}

IMUSensor::IMUSensor() {
    // set up an I2C connection with the sensor
    imu.settings.device.commInterface = IMU_MODE_I2C;    // Set mode to I2C
    imu.settings.device.mAddress = LSM9DS1_M;            // Set mag address to 0x1E
    imu.settings.device.agAddress = LSM9DS1_AG;        // Set ag address to 0x6B

    // create sensor components
    IMUGyro *gy = new IMUGyro(imu);
    IMUAccel *ac = new IMUAccel(imu);
    IMUMag *mg = new IMUMag(imu);
    gyro = gy;
    accel = ac;
    mag = mg;
}


bool IMUSensor::isStarted() {
    return imu.begin() != 0;
}

bool IMUSensor::read(int comp) {
    return getComponent(comp)->read();
}

void IMUSensor::setupGyro(int scale = 245, int sampleRate = 3, bool flipX = false,
                          bool flipY = false, bool flipZ = false) {
    imu.settings.gyro.scale = scale;
    imu.settings.gyro.sampleRate = sampleRate;
    imu.settings.gyro.flipX = flipX;
    imu.settings.gyro.flipY = flipY;
    imu.settings.gyro.flipZ = flipZ;
}

void IMUSensor::setupAccel(int scale = 4, int sampleRate = 1) {
    imu.settings.accel.scale = scale;
    imu.settings.accel.sampleRate = sampleRate;
}

void IMUSensor::setupMag(int scale = 12, int sampleRate = 5, bool tempComp = false, int operatingMode = 0) {
    imu.settings.mag.scale = scale;
    imu.settings.mag.sampleRate = sampleRate;
    imu.settings.mag.tempCompensationEnable = tempComp;
    imu.settings.mag.operatingMode = operatingMode;
}

IMUComponent *IMUSensor::getComponent(int comp) {
    if (comp == GYRO) return gyro;
    else if (comp == ACCEL) return accel;
    else return mag;
}

float IMUSensor::getX(int comp) {
    return getComponent(comp)->getX();
}

float IMUSensor::getY(int comp) {
    return getComponent(comp)->getY();

}

float IMUSensor::getZ(int comp) {
    return getComponent(comp)->getZ();
}
