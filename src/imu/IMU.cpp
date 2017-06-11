/*
 * IMUSubsystem.cpp
 *
 *  Created on: May 27, 2017
 *  Author: Deep
 *  Description: Implementation of IMU class
 */

#include "IMU.h"

IMU::IMU(unsigned int num_sensors) : sensor_total{num_sensors}{
    sensors = new IMUSensor*[sensor_total];

    for (unsigned int i = 0; i < sensor_total; i++) {
        sensors[i] = new IMUSensor;
    }
}

IMU::~IMU() {
    for (unsigned int i = 0; i < sensor_total; i++) {
        delete sensors[i];
    }

    delete sensors;
}

bool IMU::sensors_working() {
    for (unsigned int i = 0; i < sensor_total; i++) {
        if (!sensors[i]->isStarted())
            return false;
    }

    return true;
}

void IMU::serial_print(unsigned int sensor, int component) {
    float *comp_data = new float[3];

    if (sensors[sensor]->read(component)) {
        comp_data[0] = sensors[sensor]->getX(GYRO);
        comp_data[1] = sensors[sensor]->getY(GYRO);
        comp_data[2] = sensors[sensor]->getZ(GYRO);
    } else{
        comp_data[0] = comp_data[1] = comp_data[2] = stop_value;
    }

    // check of values are valid
    if (comp_data[0] < -1000 || comp_data[0] > 1000)
        comp_data[0] = stop_value;
    if (comp_data[1] < -1000 || comp_data[1] > 1000)
        comp_data[1] = stop_value;
    if (comp_data[2] < -1000 || comp_data[2] > 1000)
        comp_data[2] = stop_value;


    String sensor_name = "";

    if (component == GYRO)
        sensor_name = "gyro";
    else if (component == ACCEL)
        sensor_name = "accelerometer";
    else
        sensor_name = "magnetometer";

    Serial.println(data_handler.getJSONString(sensor_name, comp_data, 3));

    delete [] comp_data;
}


int IMU::get_sensor_total() {
    return sensor_total;
}

float IMU::get_x(unsigned int sensor, int component) {
    if (sensors[sensor]->read(component)) {
        return sensors[sensor]->getX(component);
    } else
        return stop_value;
}

float IMU::get_y(unsigned int sensor, int component) {
    if (sensors[sensor]->read(component)) {
        return sensors[sensor]->getY(component);
    } else
        return stop_value;
}

float IMU::get_z(unsigned int sensor, int component) {
    if (sensors[sensor]->read(component)) {
        return sensors[sensor]->getZ(component);
    } else
        return stop_value;
}