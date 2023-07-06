#ifndef XOROSHIRO64_H
#define XOROSHIRO64_H

#include "../../core/types.h"
#include "Splitmix64.hpp"

namespace Sequency
{
    class Xoroshiro64 {
    private:
        int64 state[2];

        int64 rotate_left(int64 x, int k)
        {
            return (x << k) | (x >> (64 - k));
        }

        void splitmix(int64 seed)
        {
            Splitmix64 sm(seed);
            state[0] = sm.generate(0, INT64_MAX);
            state[1] = sm.generate(0, INT64_MAX);
        }

    public:
        Xoroshiro64(int64 seed) {
            splitmix(seed);
        }

        int64 generate(int64 min, int64 max)
        {
            int64 s0 = state[0];
            int64 s1 = state[1];
            int64 result = s0 + s1;

            s1 ^= s0;
            state[0] = rotate_left(s0, 55) ^ s1 ^ (s1 << 14);
            state[1] = rotate_left(s1, 36);

            return min + (result % (max - min + 1));
        }
    };
}

#endif // XOROSHIRO64_H