/*
 * Lev.h
 *
 *  Created on: June 17, 2017
 *  Author: Christopher
 *  Description: Lev has the levitation related sensors.
 */

#ifndef SRC_LEVSUBSYSTEM_H_
#define SRC_LEVSUBSYSTEM_H_

#include "shared/DataHandler.h"

class Lev {
    private:
        DataHandler data_handler;
        int distance_pin;
        int dpr_pin;

public:
    Lev(int distance_pin, int dpr_pin);

    ~Lev();

    // Outputs the distance voltage in JSON format.
    void print_distance();

    // Outputs the DPR voltage in JSON format.
    void print_DPR();

    // Gets the distance voltage as measured by the photoelectric distance sensor (0V-10V)
    float get_distance();

    // Gets the DPR pressure value (0V-5V, 0-1023)
    float get_DPR();
};

#endif
