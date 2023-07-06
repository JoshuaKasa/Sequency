#include "../src/algorithms/non-cryptographic-algorithms/Squares.hpp"

#include <iostream>

#define LOOP(i, n) for (int i = 0; i < n; i++)

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

    /* MARS test
    int32 key[4] = {
            0x01234567, 0x89abcdef, 0xfedcba98, 0x76543210 // in block
    };

    MARS mars(key);

    for (int i = 0; i < 10; i++)
        cout << mars.generate() << endl;
    */

    /* Yamb test
    const int8 key[] = {
            0x12, 0x34, 0x56, 0x78
    };
    const int8 iv[] = {
            0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22
    };
    int16 key_size = 32;
    int16 iv_size = 64;

    Yamb yamb;

    yamb.keysetup(key, key_size, iv_size);
    yamb.ivsetup(iv);

    for (int i = 0; i < 10; i++)
        cout << yamb.generate(0, 0xff) << endl;*/

    /* ISAAC test
    ISAAC isaa(0x12345678);

    LOOP(i, 10)
        cout << isaa.generate(0, 0xff) << endl;*/

    /* KISS test
    KISS kiss(0x12345678);

    LOOP(i, 1000)
        cout << kiss.generate(0, 0xfffff) << endl;*/

    /* WELL test
    std::vector<int32> init = { // This will be resized to 16 entries
            0x01234567U,
            0x89abcdefU,
            0xfedcba98U,
            0x76543210U,
            0x01234567U,
            0x89abcdefU,
            0xfedcba98U,
            0x76543210U,
            0x01234567U,
            0x89abcdefU,
            0xfedcba98U,
            0x76543210U,
            0x01234567U,
            0x89abcdefU,
            0xfedcba98U,
            0x76543210U
    };

    WELL512a well(init);

    LOOP(i, 255)
        cout << well.generate() << endl;*/

    /* Salsa20 test
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

    Salsa20 salsa(key, nonce);

    LOOP(i, 255)
        cout << salsa.generate(0, 0xff) << endl; */

    /* RANROT test
    RANROT ranrot(0x12345678);

    LOOP(i, 255)
        cout << ranrot.generate(0, 0xff) << endl; */

    /* Squares test
    Squares squares(0x12345678);

    LOOP(i, 255)
        cout << squares.generate(0, 0xff) << endl; */

    return 0;
}