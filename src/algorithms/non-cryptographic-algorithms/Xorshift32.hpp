#ifndef XORSHIFT32_H
#define XORSHIFT32_H

#include "../../core/types.h"

namespace Sequency
{
    class Xorshift32 {
    private:
        int32 state;

    public:
        Xorshift32(int32 seed) : state(seed) {}

        int32 generate(int32 min, int32 max)
        {
            state ^= state << 13;
            state ^= state >> 7;
            state ^= state << 17;

            return min + (state % (max - min + 1));
        }

    };
}

#endif // XORSHIFT32_H