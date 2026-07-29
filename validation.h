#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdint.h>

uint8_t validateMenuChoice(int choice);
uint8_t validateStationName(const char *name);
uint8_t validateStationIndex(int index);

#endif
