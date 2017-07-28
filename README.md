# Waterloop pod Sensors

**Table of Contents**

- [About](#about)
- [How to Contribute](#how-to-contribute)
- [How to Code using platformIo](#how-to-code-using-platformio)
---

## About

This repository contains code for all the sensors on the Waterloop current pod.
Anyone working on sensors and scripts related to sensor data, work in this repository.
---

## How to Contribute
Anyone who is willing to work on this can clone this repo and then work on sub branch for your part.
Once finished with your part, you can make a pull request and after review the code we can
merge it to the main branch. When working on a new system, do following:

**What to Do**
* Make a separate folder insider src folder for your particular system. All the code for that system goes in that folder.
* If you need any library, add it inside lib folder.
* For testing you can create your main.cpp file but make sure there are not multiple main files. In order to avoid this,
  add your main file to `.gitignore`. This way everyone can have their separate main files.
 

---

## How to Code using platformIo
This project is created using a library called `platformio`. In order for you to use this, follow the following steps:

* Install Platformio based on your machine. Click on [**``install``**](http://docs.platformio.org/en/latest/installation.html)
  and follow the instructions.
* For writing code, you have two options:
    
**Use PlatformIo IDE (Atom)**
* For those who wants to use Atom and integrate platformIo to it, follow this [**``link``**](http://docs.platformio.org/en/latest/ide/atom.html).

**Use Clion IDE**
* For those who wants to use Clion IDE, follow this [**``link``**](http://docs.platformio.org/en/latest/ide/clion.html).
