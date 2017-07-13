//
// Created by Clive on 7/13/2017.
//

#ifndef SENSORS_ERRORCORRECTION_H
#define SENSORS_ERRORCORRECTION_H

#include <WString.h>

class ErrorCorrection {
public:
    static String encode(String str);
    static String decode(String str);
};

#endif //SENSORS_ERRORCORRECTION_H
