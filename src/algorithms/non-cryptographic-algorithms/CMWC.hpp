#ifndef CMWC_H
#define MWC_H

#include <array>
#include "../../core/types.h"

namespace Sequency
{
    class CMWC {
        std::array<int32, 4096> Q;
        int32 c = 362436;

    public:
        CMWC(int32 seed)
        {
            for (auto& x : Q)
            {
                x = seed;
                seed = (seed * 1103515245 + 12345) & 0x7fffffff;
            }
        }

        int32 generate(int32 min, int32 max)
        {
            static int32 i = 4095;
            int64 a = 18782LL;
            int32 r = 0xfffffffe;

            i = (i + 1) & 4095;

            int64 t = a * Q[i] + c;

            c = t >> 32;

            int32 x = t + c;

            if (x < c)
            {
                x++;
                c++;
            }

            return ((Q[i] = r - x) % (max - min + 1)) + min;
        }
    };
}
#endif // CMWC_H