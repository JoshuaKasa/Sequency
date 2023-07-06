#ifndef NSMB_H
#define NSMB_H

#include "../../core/types.h"

namespace Sequency {
    class NSuperMario {
    private:
        int32 state;

    public:
        NSuperMario(int32 seed) : state(seed) {}

        int32 generate(int32 min, int32 max)
        {
            int64 value = (int64)state * 0x19660D + 0x3C6EF35F;
            state = (value >> 32) + value;

            return min + (state % (max - min + 1));
        }
    };
}

#endif // NSMB_H