#pragma once
#include <concepts>
#include <vector>
#include <xieite/BigInt.hpp>

namespace xieite::math {
    template<std::integral V = int>
    constexpr std::vector<V> generatePi(std::size_t digits) noexcept {
        xieite::BigInt a = 180;
        xieite::BigInt b = 1;
        xieite::BigInt c = 60;
        xieite::BigInt d = 2;
        std::vector<V> result;
        do {
            const xieite::BigInt e = (b * (d * 27 - 12) + a * 5) / c / 5;
            const xieite::BigInt f = (d * 3 + 1) * (d * 3 + 2) * 3;
            a = (a + b * (d * 5 - 2) - c * e) * f * 10;
            b *= d * (d * 2 - 1) * 10;
            c *= f;
            ++d;
            result.push_back(static_cast<V>(e));
        } while(--digits);
        return result;
    }
}
