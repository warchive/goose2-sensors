# Waterloop pod sensors

**Table of Contents**

- [About](#about)
- [How to Contribute](#how-to-contribute)
- [IMU Sensor](#imu-sensor)
- [Scripts](#scripts)

## About
This repository contains code for all the sensors on the Waterloop current pod. As new sensors
are added, more code will be added to this repo. Anyone working on sensors and scripts related
to sensor data, work in this repository.

## How to Contribute
Anyone who is willing to work on this can clone this repo and then work on sub branch for your part.
Once finished with your part, you can make a pull request and I will review the code and then we can
merge it to the main branch. When working on a new sensor, do following:

* Make a separate folder insider src folder for your particular sensor. All the code for that sensor goes in that folder.
* Create a README file for your particular sensor and document as well as you can.
* At the end add a brief description about your sensor into the main README file in the repo. If you need help with
  how to do this, look at how IMU sensor is done.

## IMU Sensor
This library contains code to control Adafruit IMUs to reliably determine pod position. For further
documentation read [`IMU`](https://github.com/teamwaterloop/sensors/tree/master/src/imu/IMU_README.md) readme file.

## Scripts
