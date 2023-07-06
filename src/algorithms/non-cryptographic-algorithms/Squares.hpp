#ifndef SQUARES_H
#define SQUARES_H

#include "../../core/types.h"
#include "../../core/utils_functions.h"

namespace Sequency
{
    class Squares {
    private:
        int64 x, y, z;
        int64 key = 0xea3742c76bf95d47;

    public:
        Squares(int64 seed)
        {
            y = x = seed * key;
            z = y + key;
        }

        int64 generate(int64 min, int64 max)
        {
            x = x * x + y; x = rotate_left64(x, 32);
            x = x * x + z; x = rotate_left64(x, 32);

            return (((x * x + y) % (max - min + 1)) + min);
        }
    };
}

#endif // SQUARES_H