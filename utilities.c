#include "utilities.h"

int GetBit(uint8_t byte, uint8_t position){
    return byte = (byte >> position) & 1;
}

int SetBit(uint8_t byte, uint8_t position){
    return byte |= (1 << position);
}

int ClearBit(uint8_t byte, uint8_t position){
    return byte &= ~(1 << position);
}

int ToggleBit(uint8_t byte, uint8_t position){
    return byte ^= (1 << position);
}

bool IsBitSet(uint8_t byte, uint8_t position){
    bool retVal = (GetBit(byte, position)) == 1;
    return retVal;
}