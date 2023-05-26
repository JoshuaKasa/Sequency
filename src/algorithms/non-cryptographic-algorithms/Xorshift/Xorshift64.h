#ifndef XORSHIFT64_H
#define XORSHIFT64_H

#include "../../../core/types.h"

namespace Sequency
{
    class Xorshift64 {
    private:
        int64 state;

    public:
        Xorshift64(int64 seed) : state(seed) {}

        int64 generate(int64 min, int64 max)
        {
            state ^= state << 13;
            state ^= state >> 7;
            state ^= state << 17;

            return min + (state % (max - min + 1));
        }

    };
}

#endif // XORSHIFT64_H