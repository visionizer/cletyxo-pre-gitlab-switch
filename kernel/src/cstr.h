#pragma once
#include <stdint.h>

namespace Visionizer 
{
	// IF YOU ARE HERE BECAUSE OF AN OVERLOAD ERROR, YOU NEED TO CAST THE NUMBER THAT YOU WANT TO
	// TURN INTO A STRING TO THE RIGHT TYPE 
    const char* ToString(uint64_t value); // Only unsigned ints
    const char* ToString(int64_t value); // Only signed ints
    const char* ToString(double value, uint8_t decimalPlaces); // Only floats, with decimals
    const char* ToString(double value); // Only floats

}