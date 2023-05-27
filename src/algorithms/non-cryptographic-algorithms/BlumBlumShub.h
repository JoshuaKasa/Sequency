#ifndef BLUMBLUMSHUB_H
#define BLUMBLUMSHUB_H

#include "../../core/types.h"
#include "../../core/utils_functions.h"

/*
 * I'm not putting Blum Blum Shub in the "cryptographic algorithms" folder because it's not a cryptographic algorithm
 * if p and q aren't at least 1024 bits long.
 */
namespace Sequency
{
    class BlumBlumShub {
    private:
        int64 state;
        int32 p, q;
        /*
         * 32 bit integers prevent overflow and make the algorithm faster
         * Following is a list (in pairs) of good prime numbers that can be used as p and q:
            p = 383, q = 503
            p = 937, q = 967
            p = 3581, q = 3449
            p = 4637, q = 4481
            p = 5867, q = 5501
            p = 7103, q = 6869
            p = 8297, q = 8017
            p = 9377, q = 9011
            p = 10687, q = 10303
            p = 12251, q = 11827
            p = 13829, q = 13249
            p = 15217, q = 14813
            p = 61967, q = 60493
            p = 75583, q = 74093
            p = 89443, q = 87803
            p = 103681, q = 102761
            p = 117133, q = 115963
            p = 130459, q = 129389
            p = 144061, q = 142811
            p = 157327, q = 155977
            p = 170351, q = 168851
            p = 183089, q = 181499
         */

    public:
        explicit BlumBlumShub(int64 seed, int64 p, int64 q) : state(seed), p(p), q(q) {
            if (!is_prime(p) || !is_prime(q))
                throw std::invalid_argument("p and q must be prime numbers");
        }

        int64 generate(int64 min, int64 max)
        {
            state = (state * state) % (p * q);

            return min + (state % (max - min + 1));
        }
    };
}

#endif // BLUMBLUMSHUB_H
