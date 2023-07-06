#ifndef RANROT_H
#define RANROT_H

#include "../../core/types.h"
#include "../../core/utils_functions.h"

namespace Sequency
{
    class RANROT {
    private:
        static const int8 kk = 17;
        const int8 jj = 10;
        const int8 r1 = 13;
        const int8 r2 = 9;
        int32 rand_buffer[kk];
        int16 p1, p2;

    public:
        RANROT(int32 seed) : p1(0), p2(jj)
        {
            for (int8 i = 0; i < kk; i++)
            {
                seed *= 2891336453 + 1;
                rand_buffer[i] = seed;
            }

            for (int8 i = 0; i < 10; i++)
                generate(0, 1 << 31);
        }

        int32 generate(int32 min, int32 max)
        {
            int32 x = rand_buffer[p1] = rotate_left32(rand_buffer[p2], r1) + rotate_left32(rand_buffer[p1], r2);

            if (p1-- == 0)
                p1 = kk - 1;
            if (p2-- == 0)
                p2 = kk - 1;

            return ((x % (max - min + 1)) + min);
        }
    };
}

#endif // RANROT_H