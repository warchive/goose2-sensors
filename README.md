# Waterloop pod sensors

**Table of Contents**

- [About](#about)
- [How to Contribute](#how-to-contribute)
- [How to Document](#how-to-document)
- [How to Code in CLion](#how-to-code-in-clion)
- [IMU Sensor](#imu-sensor)
- [Lev Sensors](#lev-sensors)
- [Color Sensor](#color-sensor)
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
* For documentation look at [How to Document](#how-to-document) section.
* For testing you can create your main.cpp file but make sure there are not multiple main files. In order to avoid this, add your main file to `.gitignore`. This way everyone can have their separate main files.
* **Note:** You guys are writing a library for each particular sensor so follow some guidelines for how to write an [arduino library](https://www.arduino.cc/en/Hacking/LibraryTutorial). You only give access to methods that are needed by client and you do not in any way commit the client code.

## How to Document
Documentation is important in creation of any software code. Anyone working on developing sensor libraries follow rules defined below:

* Each `.h` file should contain a brief description of what that file is for. It should also contain the date it was created and your name. An example is below but you can do it your way just make sure enough information is there:
```cpp
// Created by Deep on 2017-06-27.
// Description: IMU handles accelerometer, gyroscope and magnetometer and provides
//              an interface to access the data and manage the sensors
```
* Your particular directory will contain a `README FILE` with extensive documentation of your particular library. You can include anything from how code works to research behind it.
* Modify this `README FILE` to include general things about your library. Things to include:
	* What functionality it provides
	* Any special features (if any)
	* Any limitation (if any)
	* format of data sent to dashboard in JSON format
* Link your section with the `README` in your particular sensor repository. Look at [`markdown cheatsheet`](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet) to learn more about how to link files. This will provide someone looking at your section to get more information.


## How to Code in CLion
This project is created in Clion using a library called `platformio`. In order for you to use this, follow the following steps:
* Install Clion. You can get one for free using student account.
* Install Platformio based on your machine. Click on [`install`](http://docs.platformio.org/en/latest/installation.html) and follow the instructions.
* Go to the project folder and using system terminal type `platformio init --ide clion --board megaatmega2560`. This `board` option can be different based on what board you are using. Click on [`available boards`](http://docs.platformio.org/en/latest/platforms/atmelavr.html) to learn more.
* Every time you add a library or copy paste some files or change the structure, you have to follow the above step.
* Import this project in CLion and you are good to go.
* For further help regarding this let Deep know.


## IMU Sensor
This library contains code to control Adafruit IMUs to reliably determine pod position. Basic library documentation:
* This library supports multiple IMU sensors
* Provides a method to `Serial Print` in JSON format
* Provides methods to highly customize each single sensor on IMU
* Methods provided to gather x, y and z value for each IMU sensor

**Format of data sent to Dashboard in JSON format:**

```cpp
// This contains data from Gyroscope
{"time":1009,"sensor":"gyro","data":[-1.54875,12.19750,11.36625]}

// This contains data from only Accelerometer
{"time":1009,"sensor":"accelerometer","data":[-0.02300,-0.02300,-0.02300]}

// This contains data from only Magnetometer
{"time":1009,"sensor": "magnetometer", "data":[0.41986,0.41986,0.41986]}
```

For further documentation read [`IMU`](https://github.com/teamwaterloop/sensors/tree/master/src/imu/IMU_README.md) readme file.

## Scripts
This library contains scripts for data processing and functional estimation. It is intended as a generic mathematical toolkit that can be used for various sensor data types. The current files include:
* halbach_model.py - Theoretical models for the halbach wheel
* RF.py - random forest regression model for functional estimation of sample errors
* SVR.py - support vector regression model with radial basis function kernel to fit a smooth curve over raw data
* SVR_demo.py - a graphical demo of the process using randomly generated data
* test.py - a useful tool to generate mock data sets (current PRNG model is U(a,b) but can be changed to fit project needs)
* FakeData.csv - randomly generated test set containing 1000 lines of time-x-y-z data points.<br/>

Invoke the scripts from the node server in the following order:
SVR.py -> halbach_model.py -> RF.py (this will perform preliminary curve smoothing, theoretical value calculations, and regression on the error range) <br/> <br/>
* SVR.py: A general-purpose data processing tool for any time-vs-XYZ data. Function SVR_process_monotype(JSONArray) takes an array of JSON objects of the same type, processes the data, then returns the array of objects in the same format as the input. If the script is run in a standalone sandbox, the demo script also executes & produces a simulation graph.
