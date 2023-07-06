#ifndef XORSHIFT32WOW_H
#define XORSHIFT32WOW_H

#include "../../core/types.h"

namespace Sequency
{
    class XORShift32Wow {
    private:
        uint32_t state1, state2, state3;

    public:
        XORShift32Wow(uint32_t seed) : state1(seed), state2(seed), state3(seed) {}

        uint32_t generate(int32 min, int32 max)
        {
            uint32_t t = state1;

            t ^= t << 11;
            t ^= t >> 8;
            state1 = state2;
            state2 = state3;
            state3 ^= state3 >> 19 ^ t ^ t >> 8;

            return min + (state3 % (max - min + 1));
        }
    };

}

#endif // XORSHIFT32WOW_H