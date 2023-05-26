#include "..\src\algorithms\non-cryptographic-algorithms\ACORN\ACORN.h"

#include <iostream>

using namespace std;
using namespace Sequency;

int main()
{
    ACORN ms(120, 1 << 30);

    for (int i = 0; i < 1000; i++)
    {
        cout << ms.generate() << endl;
    }

    return 0;
}