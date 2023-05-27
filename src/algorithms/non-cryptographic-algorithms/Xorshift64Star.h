#ifndef XORSHIFTSTAR_H
#define XORSHIFTSTAR_H

#include "../../core/types.h"

namespace Sequency
{
    class Xorshift64Star
            {
    private:
        int64 state;

    public:
        Xorshift64Star(int64 seed) : state(seed) {}

        int64 generate(int64 min, int64 max)
        {
            state ^= state << 13;
            state ^= state >> 7;
            state ^= state << 17;
            state = state * 0x2545F4914F6CDD1DULL;

            return min + (state % (max - min + 1));
        }

    };
}

#endif // XORSHIFTSTAR_H