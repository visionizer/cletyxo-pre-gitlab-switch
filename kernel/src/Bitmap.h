#pragma once
#include <stddef.h>
#include <stdint.h>


namespace Visionizer
{
    class Bitmap 
    {
    public:
        size_t Size;
        uint8_t* Buffer;
        bool operator[](uint64_t index); // Use like a normal array
        void Set(uint64_T index, bool value);
    };
}