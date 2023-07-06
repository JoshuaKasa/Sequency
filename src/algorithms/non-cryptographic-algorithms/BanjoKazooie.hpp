#ifndef BANKOKAZOOIE_H
#define BANKOKAZOOIE_H

#include "../../core/types.h"

// Banjo-Kazooie's RNG algorithm
namespace Sequency
{
    class BanjoKazooie {
    private:
        int32 state;
        int32 previous_random_1 = 0x86D;
        int32 previous_random_2 = 0x2c060731;
        int32 random_update_1 = 0x19f0458b;
        int32 random_update_2 = 0x86D;
        int32 random_value_1 = 0x2c060731;
        int32 random_value_2 = 0x19f0458b;

    public:
        BanjoKazooie(int32 seed) : state(seed) {}

        int32 generate(int32 min, int32 max)
        {
            if (previous_random_2 & 3)
            {
                previous_random_2 = ((random_update_1++) + (previous_random_2 >> 2)) + (previous_random_1 >> 6);

                state += ((previous_random_1 + previous_random_2) % 0x2710) / 10000;
            }
            else
            {
                previous_random_2 = (previous_random_1 * 0xCDD / 100);
                previous_random_2 += (previous_random_1 >> 8) + (random_update_1 >> 0xd);
                random_update_1 *= (previous_random_2 & 0x30f1);
                previous_random_2 = (previous_random_2 ^ 0x3fffffff) >> 2;
                previous_random_2 &= 0x7fffff;
                previous_random_2 = (previous_random_2 + random_update_1) & 0xfffff;
                previous_random_1 ^= previous_random_2;
                previous_random_1 = (previous_random_1 >> (previous_random_2 & 3)) & 0x3fffffff;

                state += (previous_random_1 % 0x186A0) / 100000;
            }

            return min + (state % (max - min + 1));
        }
    };
}

#endif // BANKOKAZOOIE_H