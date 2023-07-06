#ifndef SPLITMIX64_H
#define SPLITMIX64_H

#include "../../core/types.h"

namespace Sequency
{
    class ParkMiller {
    private:
        int32 state;

    public:
        ParkMiller(int32 seed) : state(seed) {}

        int32 generate(int32 min, int32 max)
        {
            state = 16807 * (state % 127773) - 2836 * (state / 127773);

            if (state <= 0)
                state += 2147483647;

            return min + (state % (max - min + 1));
        }
    };
}

#endif // SPLITMIX64_H