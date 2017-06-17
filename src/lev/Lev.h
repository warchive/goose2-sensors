/*
 * Lev.h
 *
 *  Created on: June 17, 2017
 *  Author: Christopher
 *  Description: Lev has the levitation related sensors.
 */

#ifndef SRC_LEVSUBSYSTEM_H_
#define SRC_LEVSUBSYSTEM_H_

#define DISTANCE_PIN 0
#define DPR_PIN 1

#include "shared/DataHandler.h"

class Lev {
    private:
        DataHandler data_handler;

public:
    Lev();

    ~Lev();

    int get_distance();

    // Gets the DPR pressure value (0V-5V, 0-1023)
    int get_DPR();
};

#endif
