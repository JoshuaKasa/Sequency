#ifndef PCG_H
#define PCG_H

#include "../../core/types.h"

namespace Sequency
{
    class PCG {
    private:
        int64 state;
        int64 inc;

    public:
        PCG(int64 seed, int64 seq) : state(seed), inc(seq) {}

        int32 generate(int32 min, int32 max)
        {
            int64 oldstate = state;

            state = oldstate * 6364136223846793005ULL + inc;

            int32 xorshifted = static_cast<int32>(((oldstate >> 18u) ^ oldstate) >> 27u);
            int32 rot = static_cast<int32>(oldstate >> 59u);

            return min + ((xorshifted >> rot) | (xorshifted << ((-rot) & 31))) % (max - min + 1);
        }
    };
}

#endif // PCG_H