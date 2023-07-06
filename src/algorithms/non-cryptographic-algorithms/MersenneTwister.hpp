#ifndef MERSENNETWISTER_H
#define MERSENNETWISTER_H

#include "../../core/types.h"

namespace Sequency
{
    class MersenneTwister
    {
    private:
        static constexpr int32 N = 624;
        static constexpr int32 M = 397;
        static constexpr int32 MATRIX_A = 0x9908b0dfUL;
        static constexpr int32 UPPER_MASK = 0x80000000UL;
        static constexpr int32 LOWER_MASK = 0x7fffffffUL;

        uint32_t mt[N];
        uint32_t index;

    public:
        MersenneTwister(int32 seed)
        {
            initialize(seed);
        }

        void initialize(int32 seed)
        {
            mt[0] = seed;
            for (uint32_t i = 1; i < N; ++i)
            {
                mt[i] = (1812433253UL * (mt[i - 1] ^ (mt[i - 1] >> 30)) + i);
            }
            index = N;
        }

        int32 generate(int32 min, int32 max)
        {
            if (index >= N)
            {
                twist();
            }

            int32 y = mt[index];

            y ^= (y >> 11);
            y ^= (y << 7) & 0x9d2c5680UL;
            y ^= (y << 15) & 0xefc60000UL;
            y ^= (y >> 18);

            index++;

            return y;
        }

    private:
        void twist()
        {
            for (int32 i = 0; i < N; ++i)
            {
                int32 x = (mt[i] & UPPER_MASK) + (mt[(i + 1) % N] & LOWER_MASK);
                int32 xA = x >> 1;

                if (x % 2 != 0)
                {
                    xA ^= MATRIX_A;
                }

                mt[i] = mt[(i + M) % N] ^ xA;
            }

            index = 0;
        }
    };
}

#endif // MERSENNETWISTER_H