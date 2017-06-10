/*
 * IMUSubsystem.cpp
 *
 *  Created on: May 27, 2017
 *  Author: Deep
 *  Description: Implementation of IMU class
 */

#include "IMU.h"

IMU::IMU(unsigned int num_sensors) : sensor_total{num_sensors}{
    for (unsigned int i = 0; i < sensor_total; i++) {
        sensors.push_back(new IMUSensor);
    }
}

IMU::~IMU() {
    for (unsigned int i = 0; i < sensor_total; i++) {
        delete(sensors.at(i));
        sensors.pop_back();
    }
}

bool IMU::sensors_working() {
    for (unsigned int i = 0; i < sensor_total; i++) {
        if (!sensors.at(i)->isStarted())
            return false;
    }

    return true;
}

void IMU::serial_print(unsigned int sensor, int component) {
    float comp_data[3];

    if (sensors.at(sensor)->read(component)) {
        comp_data[0] = sensors.at(sensor)->getX(GYRO);
        comp_data[1] = sensors.at(sensor)->getY(GYRO);
        comp_data[2] = sensors.at(sensor)->getZ(GYRO);
    }

    String sensor_name = "";

    if (component == GYRO)
        sensor_name = "gyro";
    else if (component == ACCEL)
        sensor_name = "accelerometer";
    else
        sensor_name = "magnetometer";

    Serial.println(data_handler.getJSONString(sensor_name, comp_data, 3));
}


int IMU::get_sensor_total() {
    return sensor_total;
}

float IMU::get_x(unsigned int sensor, int component) {
    if (sensors.at(sensor)->read(component)) {
        return sensors.at(sensor)->getX(component);
    } else
        return stop_value;
}

float IMU::get_y(unsigned int sensor, int component) {
    if (sensors.at(sensor)->read(component)) {
        return sensors.at(sensor)->getY(component);
    } else
        return stop_value;
}

float IMU::get_z(unsigned int sensor, int component) {
    if (sensors.at(sensor)->read(component)) {
        return sensors.at(sensor)->getZ(component);
    } else
        return stop_value;
}