# Waterloop pod sensors

**Table of Contents**

- [About](#about)
- [How to Contribute](#how-to-contribute)
- [How to Code in CLion](#how-to-code-in-clion)
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
* For testing you can create your main.cpp file but make sure there are not multiple main files. In order to avoid this,
  add your main file to `.gitignore`. This way everyone can have their separate main files.

## How to Code in CLion
This project is created in Clion using a library called `platformio`. In order for you to use this, follow the following steps:
* Install Clion. You can get one for free using student account.
* Install Platformio based on your machine. Click on [`install`](http://docs.platformio.org/en/latest/installation.html)
  and follow the instructions.
* Go to the project folder and using system terminal type `platformio init --ide clion --board megaatmega2560`. This `board` option
  can be different based on what board you are using. Click on [`available boards`](http://docs.platformio.org/en/latest/platforms/atmelavr.html)
  to learn more.
* Every time you add a library or copy paste some files or change the structure, you have to follow the above
  step.
* Import this project in CLion and you are good to go.
* For further help regarding this let Deep Dhillon know.
  

## IMU Sensor
This library contains code to control Adafruit IMUs to reliably determine pod position. For further
documentation read [`IMU`](https://github.com/teamwaterloop/sensors/tree/master/src/imu/IMU_README.md) readme file.

## Scripts
