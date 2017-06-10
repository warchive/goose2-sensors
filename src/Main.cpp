#include <Arduino.h>
#include "imu/IMU.h"

// create a subsystem of 1 sensors
IMU im(1);

void setup() {
    Serial.begin(115200);
    delay(1000);

    if (im.sensors_working()) {
        Serial.println("All sensors working");
    } else {
        Serial.println("Not working");
        Serial.println("Infinite loop");
        while (1){

        }
    }
}


void loop() {
    delay(500);
    im.serialPrint(0, GYRO);
}
