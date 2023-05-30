#ifndef KISS_H
#define KISS_H

#include "../../core/types.h"

namespace Sequency
{
    class KISS
    {
    private:
        uint64_t x, y, z, c;

    public:
        KISS(uint64_t seed) : x(123456789), y(987654321), z(43219876), c(seed) {}

        uint64_t generate(int64 min, int64 max)
        {
            x = 69069 * x + 12345;
            y ^= y << 13;
            y ^= y >> 17;
            y ^= y << 5;

            uint64_t t = 698769069ULL * z + c;

            c = t >> 32;
            z = static_cast<uint64_t>(t);

            int64 result = x + y + z;

            return result % (max - min + 1) + min;
        }
    };
}

#endif // KISS_H