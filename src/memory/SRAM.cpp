#include <MemoryFree.h>
#include "SRAM.h"

SRAM::SRAM(const String name) : Sensor{name, 60, 1} {}

float SRAM::read() {
    add(freeMemory());
    return 0;
}
