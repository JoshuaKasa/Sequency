#include "../src/algorithms/cryptographic-algorithms/MARS.h"
#include "../src/algorithms/non-cryptographic-algorithms/Xoroshiro64.h"

#include <iostream>

using namespace std;
using namespace Sequency;

int main()
{
    /* ChaCha20 test

     int8 key[32] = {
                        0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
                        0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
                        0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11,
                        0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
                        0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
                        0x1E, 0x1F
    };
    int8 nonce[8] = {
                        0x01, 0x02, 0x03, 0x04,
                        0x05, 0x06, 0x07, 0x08
    };

    ChaCha20 chacha(key, nonce);

    for (int i = 0; i < 10; i++)
        cout << chacha.generate(0, 0xff) << endl;

     */

    /* Twofish test
    int8 key[32] = {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
            0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B,
            0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11,
            0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
            0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
            0x1E, 0x1F
    };

    Twofish twofish(key);

    for (int i = 0; i < 10; i++)
        cout << twofish.generate(0, 0xff) << endl;

        */

    /* MARS test */
    Xoroshiro64 xoroshiro64(0x12345678);

    int32 key1[47];
    int32 key2[40];
    int32 key_in[] = {0x12345678, 0x9abcdef0, 0xdeadbeef,};
    int32 key_len = sizeof(key_in) / sizeof(key_in[0]);
    int32 seed = 0x93CD3A2C;

    // Generating the 2 keys (47 and 40 entries of 32 bits) using XoroShiro64
    for (unsigned int & i : key1)
        i = xoroshiro64.generate(0, 0xffffffff);
    for (unsigned int & i : key2)
        i = xoroshiro64.generate(0, 0xffffffff);

    Sequency::MARS mars(seed, key1, key2);

    for (int i = 0; i < 10; i++)
        cout << mars.generate(0, 0xffffffff) << endl;


    return 0;
}