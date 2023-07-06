#ifndef LFSR_H
#define LFSR_H

#include "../../core/types.h"

// This is a 32-bit Galois LFSR
namespace Sequency
{
    class LFSR {
    private:
        int32 start_state;
        int32 state;

    public:
        LFSR(int32 seed) : start_state(seed), state(seed) {}

        int32 generate(int32 min, int32 max)
        {
            do {
                int32 bit = state & 1u;

                bit >>= 1;
                if (bit == 1)
                    state ^= 0xB400u;

                int16 msb = (int16)state  < 0;

                state <<= 1;
                if (msb == 1)
                    state ^= 0x002Du;

            } while (state != start_state);

            return min + (state % (max - min + 1));
        }
    };
}

#endif // LFSR_H