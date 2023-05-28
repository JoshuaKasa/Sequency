#ifndef LFG_H
#define LFG_H

#include "../../core/types.h"
#include <vector>

namespace Sequency // This is the namespace for the whole project
{
    class LaggedFibonacciGenerator {
    private:
        static constexpr int32 lag = 55;
        static constexpr int32 lag1 = 24;
        static constexpr int32 lag2 = 55 - lag1;
        std::vector<int32> state;

    public:
        LaggedFibonacciGenerator(int32 seed)
        {
            state.resize(lag);
            state[0] = seed;
            for (int i = 1; i < lag; ++i)
                state[i] = (16807 * state[i - 1]) % 2147483647;
        }

        int32 generate(int32 min, int32 max)
        {
            int32 next = (state[lag - lag1] + state[lag - lag2]) % 2147483647;

            state.push_back(next);
            state.erase(state.begin());

            return min + (next % (max - min + 1));
        }
    };
}

#endif // LFG_H