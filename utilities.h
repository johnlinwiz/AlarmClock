/* 
 * File:   utilities.h
 * Author: Sean Wernimont (@swernimo)
 *
 */

#ifndef utilities
#define	utilities

#include <stdint.h>
#include <stdbool.h>

int GetBit(uint8_t byte, uint8_t position);
int SetBit(uint8_t byte, uint8_t position);
int ClearBit(uint8_t byte, uint8_t position);
int ToggleBit(uint8_t byte, uint8_t position);
bool IsBitSet(uint8_t byte, uint8_t position);

#endif

