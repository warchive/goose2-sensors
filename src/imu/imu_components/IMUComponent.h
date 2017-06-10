/*
 * IMUComponent.h
 *
 *  Created on: May 24, 2017
 *  Author: Deep Dhillon
 *  Description: Definition and documentation of IMUComponent class. This class acts as a parent class to all the
 *  			 components that are a part of IMUSensor
 */

#ifndef SRC_IMUCOMPONENT_H_
#define SRC_IMUCOMPONENT_H_

#include "SparkFunLSM9DS1.h"

class IMUComponent {
protected:
    float x;
    float y;
    float z;

public:
    IMUComponent();

    virtual ~IMUComponent();

    // read() gathers data from the component and updates values related to it
    virtual bool read() = 0;

    // getX() returns the x value of the component
    virtual float getX() = 0;

    // getY() returns the y value of the component
    virtual float getY() = 0;

    // getZ() returns the z value of the component
    virtual float getZ() = 0;
};

#endif
