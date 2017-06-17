/*
 *  Lev.cpp
 *
 *  Created on: June 17, 2017
 *  Author: Christopher
 *  Description: Implementation of the lev class
 */

#include "Lev.h"

Lev::Lev() {

}

Lev::~Lev() {

}

int Lev::get_distance() {
	return analogRead(DISTANCE_PIN)
}

int Lev::get_DPR() {
	return analogRead(DPR_PIN);
}