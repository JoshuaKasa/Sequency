#ifndef LCG_H
#define LCG_H

#include "../../core/types.h"

namespace Sequency
{
    class LCG {
    private:
        int32 seed;
        int32 multiplier = 214013;
        int32 increment = 2531011;
        int32 modulus = 1 << 31;

    public:
        LCG(int32 seed) : seed(seed) {}

        int32 generate(int32 min, int32 max)
        {
            seed = (multiplier * seed + increment) % modulus;

            return min + (seed % (max - min));
        }

    };
}

#endif // LCG_H