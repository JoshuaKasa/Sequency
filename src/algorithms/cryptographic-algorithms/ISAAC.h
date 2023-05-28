#ifndef ISAAC_H
#define ISAAC_H

#include "../../core/types.h"

namespace Sequency {
    class ISAAC {
    private:
        int32 randRsl[256];
        int32 randCnt;

        int32 mm[256];
        int32 aa, bb, cc;

        void isaac()
        {
            ++cc;
            bb += cc;

            for (int32 i = 0; i < 256; ++i)
            {
                int32 x, y;

                x = mm[i];
                switch (i % 4)
                {
                    case 0:
                        aa = aa ^ (aa << 13);
                        break;
                    case 1:
                        aa = aa ^ (aa >> 6);
                        break;
                    case 2:
                        aa = aa ^ (aa << 2);
                        break;
                    case 3:
                        aa = aa ^ (aa >> 16);
                        break;
                }
                aa = mm[(i + 128) % 256] + aa;
                y = mm[(x >> 2) % 256] + aa + bb;
                mm[i] = y;
                bb = mm[(y >> 10) % 256] + x;
                randRsl[i] = bb;
            }
            randCnt = 0;
        }

        void mix(int32 a[])
        {
            a[0] = a[0] ^ a[1] << 11;
            a[3] += a[0];
            a[1] += a[2];
            a[1] = a[1] ^ a[2] >> 2;
            a[4] += a[1];
            a[2] += a[3];
            a[2] = a[2] ^ a[3] << 8;
            a[5] += a[2];
            a[3] += a[4];
            a[3] = a[3] ^ a[4] >> 16;
            a[6] += a[3];
            a[4] += a[5];
            a[4] = a[4] ^ a[5] << 10;
            a[7] += a[4];
            a[5] += a[6];
            a[5] = a[5] ^ a[6] >> 4;
            a[0] += a[5];
            a[6] += a[7];
            a[6] = a[6] ^ a[7] << 8;
            a[1] += a[6];
            a[7] += a[0];
            a[7] = a[7] ^ a[0] >> 9;
            a[2] += a[7];
            a[0] += a[1];
        }

        void randInit(bool flag)
        {
            int32 a[8];
            aa = bb = cc = 0;

            a[0] = 2654435769UL;
            for (int32 j = 1; j < 8; ++j)
                a[j] = a[0];

            for (int32 i = 0; i < 4; ++i)
                mix(a);
            for (int32 i = 0; i < 256; i += 8)
            {
                if (flag)
                    for (int32 j = 0; j < 8; ++j)
                        a[j] += randRsl[i + j];
                mix(a);
                for (int32 j = 0; j < 8; ++j)
                    mm[i + j] = a[j];
            }

            if (flag)
            {
                for (int32 i = 0; i < 256; i += 8)
                {
                    for (int32 j = 0; j < 8; ++j)
                        a[j] += mm[i + j];
                    mix(a);
                    for (int32 j = 0; j < 8; ++j)
                        mm[i + j] = a[j];
                }
            }

            isaac();
            randCnt = 0;
        }

    public:
        ISAAC(int32 seed) : randCnt(0)
        {
            randCnt = 0;
            randRsl[0] = seed;
            for (uint32_t i = 1; i < 256; ++i)
                randRsl[i] = seed = (1812433253UL * (seed ^ (seed >> 30)) + i) & 0xffffffffUL;
            randInit(true);
        }

        int32 generate(int32 min, int32 max)
        {
            int32 result = randRsl[randCnt];
            ++randCnt;
            if (randCnt > 255)
            {
                isaac();
                randCnt = 0;
            }
            return result % (max - min + 1) + min;
        }
    };
}

#endif // ISAAC_H