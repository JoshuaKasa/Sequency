#ifndef SPLITMIX64_H
#define SPLITMIX64_H

#include "../../core/types.h"

namespace Sequency
{
    class Splitmix64
    {
    private:
        int64 state;

    public:
        Splitmix64(int64 seed) : state(seed) {}

        int64 generate(int64 min, int64 max)
        {
            int64 z = (state += 0x9E3779B97F4A7C15ULL);

            z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
            z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;

            return min + (z ^ (z >> 31)) % (max - min + 1);
        }

    };
}

#endif // SPLITMIX64_H