#ifndef CHACHA20_H
#define CHACHA20_H

#include <string>
#include <vector>
#include "../../core/types.h"

namespace Sequency {
    class ChaCha20 {
    private:
        std::vector<int32> state;
        int32 counter;

        static void quarterRound(int32& a, int32& b, int32& c, int32& d)
        {
            a += b; d ^= a; d = (d << 16) | (d >> 16);
            c += d; b ^= c; b = (b << 12) | (b >> 20);
            a += b; d ^= a; d = (d << 8) | (d >> 24);
            c += d; b ^= c; b = (b << 7) | (b >> 25);
        }

        void nextState()
        {
            std::vector<int32> tempState = state;

            for (int i = 0; i < 10; i++)
            {
                quarterRound(tempState[0], tempState[4], tempState[8], tempState[12]);
                quarterRound(tempState[1], tempState[5], tempState[9], tempState[13]);
                quarterRound(tempState[2], tempState[6], tempState[10], tempState[14]);
                quarterRound(tempState[3], tempState[7], tempState[11], tempState[15]);
                quarterRound(tempState[0], tempState[5], tempState[10], tempState[15]);
                quarterRound(tempState[1], tempState[6], tempState[11], tempState[12]);
                quarterRound(tempState[2], tempState[7], tempState[8], tempState[13]);
                quarterRound(tempState[3], tempState[4], tempState[9], tempState[14]);
            }

            for (int i = 0; i < 16; i++)
                state[i] += tempState[i];

            counter++;
        }

    public:
        ChaCha20(const int8* key, const int8* nonce)
        {
            state.resize(16);

            // Set constant values
            state[0] = 0x61707865;
            state[1] = 0x3320646e;
            state[2] = 0x79622d32;
            state[3] = 0x6b206574;

            // Set key
            memcpy(&state[4], key, 32);

            // Set nonce
            state[12] = 0;
            state[13] = 0;
            memcpy(&state[14], nonce, 8);

            counter = 0;
        }

        int32 generate(int32 min, int32 max)
        {
            if (counter % 16 == 0)
                nextState();

            int32 result = state[counter % 16];
            counter++;

            return min + (result % (max - min + 1));
        }
    };
}

#endif // CHACHA20_H