#include "ColorSensor.h"


// limit() restricts the value to 0 and based on the bound
uint8_t limit(const int value, const int bound){
    if (value >= bound) return 1;
    else return 0;
}


uint8_t ColorSensor::getLimitOut1() {
    //Limiting outputs to 0 & 1, instead of 0 - 1023
    return limit(analogRead(out1APin), 1000);
}


uint8_t ColorSensor::getLimitOut2() {
    //Limiting outputs to 0 & 1, instead of 0 - 1023
    return limit(analogRead(out2APin), 1000);
}


uint8_t ColorSensor::getLimitOut3() {
    //Limiting outputs to 0 & 1, instead of 0 - 1023
    return limit(analogRead(out3APin), 1000);
}


uint8_t ColorSensor::getColorRange() {
    uint8_t out1 = getLimitOut1();
    uint8_t out2 = getLimitOut2();
    uint8_t out3 = getLimitOut3();

    if (out1 == 0 && out2 == 0 && out3 == 0) return 0;          // 0 is background (black, dark_blue)
    else if (out1 == 0 && out2 == 0 && out3 == 1) return 1;     // 1 is Red, brown, pinkish-red, orange
    else if (out1 == 0 && out2 == 1 && out3 == 0) return 2;     // 2 is Yellow, orange
    else if (out1 == 0 && out2 == 1 && out3 == 1) return 3;
    else if (out1 == 1 && out2 == 0 && out3 == 0) return 4;     // 4 is White,
                                                                // green_tape_in_bay (out 2 flickers sometimes),
                                                                // light_blue,
    else if (out1 == 1 && out2 == 0 && out3 == 1) return 5;
    else if (out1 == 1 && out2 == 1 && out3 == 0) return 6;
    else if (out1 == 1 && out2 == 1 && out3 == 1) return 7;
}


void ColorSensor::serialPrint() {
    float *data = new float[1];

    data[0] = getColorRange();

    data_handler.getJSONString("color", data, 1);
}



/*
void Color_Sensor::counter() {
    //2 loops that look at the change from Out1 == 0 to Out1 == 1, to count the # of times the orange stripe has been 'seen' by the sensor

    Serial.begin(9600);
    float *colorData = new float(4);

    if (out1 == 1 && out2 == 0 && out3 == 0) {
        if (temp == 0) {
            count++;
            temp = out1;
        } else if (temp == 1) {
            temp = out1;
        }
    }

    if (out1 == 0 && out2 == 0 && out3 == 0) {
        if (temp == 0) {
            temp = out1;
        } else if (temp == 1) {
            count++;
            temp = out1;
        }
    }

    String sensor_name = "Color";

    colorData[0] = out1,
            colorData[1] = out2;
    colorData[2] = out3;
    colorData[3] = count;

    Serial.println(data_handler.getJSONString(sensor_name, colorData, 4));

    delete[] colorData;

}



*/