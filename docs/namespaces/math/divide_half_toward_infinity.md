# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideHalfTowardInfinity\<\>\(\)
Defined in header [<xieite/math/divide_half_toward_infinity.hpp>](../../../include/xieite/math/divide_half_toward_infinity.hpp)

&nbsp;

## Description
Computes a quotient and rounds [half toward infinity](https://en.wikipedia.org/wiki/Rounding#Rounding_half_away_from_zero).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ divideHalfTowardInfinity(Arithmetic_ dividend, Arithmetic_ divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_half_toward_infinity.hpp"

int main() {
    std::println("{}", xieite::math::divideHalfTowardInfinity(5, 2));
    std::println("{}", xieite::math::divideHalfTowardInfinity(5, -2));
    std::println("{}", xieite::math::divideHalfTowardInfinity(-5, 2));
    std::println("{}", xieite::math::divideHalfTowardInfinity(-5, -2));
}
```
Output:
```
3
-3
-3
3
```
