//
// Created by Clive on 7/13/2017.
//

#ifdef UNIT_TEST

#include <unity.h>
#include <Arduino.h>
#include <WString.h>
#include "../lib/ErrorCorrection/ErrorCorrection.h"
#include <iostream>

void test_ErrorCorrection_random_errors(void){
    int length = random(200, 500);
    int bitflips = length / 2;
    String s;
    s.reserve(length);
    for (int i = 0; i < length; i++) {
        char letter = random(0, 256);
        s += letter;
    }

    String encoded = ErrorCorrection::encode(s);

    for (int i = 0; i < bitflips; i++) {
        char& c = s[random(0, length)];
        c ^= 1 << random(0, 8);
    }

    String decoded = ErrorCorrection::decode(s);

    TEST_ASSERT(s == decoded);
}

int main(){
    randomSeed(24601);
    delay(2000);
    UNITY_BEGIN();
    for(int i = 0; i < 10; i++)
        RUN_TEST(test_ErrorCorrection_random_errors);
    UNITY_END();
}

#endif //UNIT_TEST
