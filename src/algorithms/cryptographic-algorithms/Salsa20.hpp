#ifndef SALSA20_H
#define SALSA20_H

#include "../../core/types.h"
#include "../../core/utils_functions.h"

namespace Sequency
{
    class Salsa20 {
    private:
        int32 state[16];

        void quarterRound(int32& a, int32& b, int32& c, int32& d)
        {
            b ^= rotate_left32(a + d, 7);
            c ^= rotate_left32(b + a, 9);
            d ^= rotate_left32(c + b, 13);
            a ^= rotate_left32(d + c, 18);
        }

        void doubleround()
        {
            // Column round
            quarterRound(state[0], state[4], state[8], state[12]);
            quarterRound(state[5], state[9], state[13], state[1]);
            quarterRound(state[10], state[14], state[2], state[6]);
            quarterRound(state[15], state[3], state[7], state[11]);
            // Diagonal round
            quarterRound(state[0], state[1], state[2], state[3]);
            quarterRound(state[5], state[6], state[7], state[4]);
            quarterRound(state[10], state[11], state[8], state[9]);
            quarterRound(state[15], state[12], state[13], state[14]);
        }

    public:
        Salsa20(const int8* key, const int8* nonce)
        {
            // Constants, the "expand 32-byte k" in little-endian
            state[0] = 0x61707865;  // "expa"
            state[1] = 0x3320646e;  // "nd 3"
            state[2] = 0x79622d32;  // "2-by"
            state[3] = 0x6b206574;  // "te k"

            // Key
            for (int i = 0; i < 8; ++i)
                state[4 + i] = load32_le(key + (4 * i));

            // Nonce
            state[14] = load32_le(nonce);
            state[15] = load32_le(nonce + 4);
        }

        int32 generate(int32 min, int32 max)
        {
            doubleround();

            int32 result = state[0];
            state[8]++;
            if (state[8] == 0)
                state[9]++;

            return result % (max - min + 1) + min;
        }

    private:
        int32 load32_le(const int8* data) {
            return (data[0]) | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
        }

        void store32_le(int8* data, int32 value)
        {
            data[0] = value & 0xff;
            data[1] = (value >> 8) & 0xff;
            data[2] = (value >> 16) & 0xff;
            data[3] = (value >> 24) & 0xff;
        }
    };
}

#endif // SALSA20_H