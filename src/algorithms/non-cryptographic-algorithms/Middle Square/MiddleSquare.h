#ifndef MIDDLESQUARE_H
#define MIDDLESQUARE_H

#include "../../../core/types.h"

namespace Sequency
{
    class MiddleSquare {
    private:
        int64 state;
        int32 seed_length;

    public:
        MiddleSquare(int32 seed) : state(seed), seed_length(get_seed_length(seed)) {}

        int32 generate(int32 min, int32 max)
        {
            state *= state;
            state >>= calculate_shift_amount(seed_length);

            return min + (state % (max - min + 1));
        }

    private:
        int32 get_seed_length(int32 seed)
        {
            int32 length = 0;

            while (seed > 0)
            {
                seed /= 10;
                length++;
            }

            return length;
        }

        int32 calculate_shift_amount(int32 length)
        {
            int32 shift_amount = (length % 2 == 0) ? length / 2 : (length + 1) / 2;
            return shift_amount;
        }
    };

}

#endif // MIDDLESQUARE_H