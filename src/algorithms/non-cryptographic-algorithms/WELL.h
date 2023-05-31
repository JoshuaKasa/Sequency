#ifndef WELL512_H
#define WELL512_H

#include <vector>
#include "../../core/types.h"

constexpr int R = 16;
constexpr int M1 = 13;
constexpr int M2 = 9;
constexpr int M3 = 5;

constexpr double FACT = 2.32830643653869628906e-10;

namespace Sequency
{
    class WELL512a {
    public:
        WELL512a(const std::vector<int32>& init) : state_i(0), STATE(init) {
            STATE.resize(R);
        }

        double generate()
        {
            int32 z0 = VRm1();
            int32 z1 = MAT0NEG(-16, V0()) ^ MAT0NEG(-15, VM1());
            int32 z2 = MAT0POS(11, VM2());

            STATE[state_i] = z1 ^ z2;
            STATE[(state_i + 15) & 0x0000000fU] = MAT0NEG(-2, z0) ^ MAT0NEG(-18, z1) ^ MAT3NEG(-28, z2) ^ MAT4NEG(-5, 0xda442d24U, newV1());
            state_i = (state_i + 15) & 0x0000000fU;

            return static_cast<double>(STATE[state_i]) * FACT;
        }

    private:
        int32 MAT0POS(int32 t, int32 v) {
            return v ^ (v >> t);
        }

        int32 MAT0NEG(int32 t, int32 v) {
            return v ^ (v << (-t));
        }

        int32 MAT3NEG(int32 t, int32 v) {
            return v << (-t);
        }

        int32 MAT4NEG(int32 t, int32 b, int32 v) {
            return v ^ ((v << (-t)) & b);
        }

        int32 V0() {
            return STATE[state_i];
        }

        int32 VM1() {
            return STATE[(state_i + M1) & 0x0000000fU];
        }

        int32 VM2() {
            return STATE[(state_i + M2) & 0x0000000fU];
        }

        int32 VM3() {
            return STATE[(state_i + M3) & 0x0000000fU];
        }

        int32 VRm1() {
            return STATE[(state_i + 15) & 0x0000000fU];
        }

        int32 VRm2() {
            return STATE[(state_i + 14) & 0x0000000fU];
        }

        int32 newV0() {
            return STATE[(state_i + 15) & 0x0000000fU];
        }

        int32 newV1() {
            return STATE[state_i];
        }

        int32 newVRm1() {
            return STATE[(state_i + 14) & 0x0000000fU];
        }

    private:
        int32 state_i;
        std::vector<int32> STATE;
    };
}

#endif // WELL512_H