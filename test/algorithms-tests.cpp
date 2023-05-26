#include "..\src\algorithms\non-cryptographic-algorithms\Xorshift\Xoroshiro64.h"

#include <iostream>

using namespace std;
using namespace Sequency;

int main()
{
    Xoroshiro64 xoroshiro64(123456789);

    for (int i = 0; i < 10; i++)
    {
        cout << xoroshiro64.generate(0, 100) << endl;
    }

    return 0;
}