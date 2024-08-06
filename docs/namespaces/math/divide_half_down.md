# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideHalfDown\<\>\(\)
Defined in header [<xieite/math/divide_half_down.hpp>](../../../include/xieite/math/divide_half_down.hpp)

&nbsp;

## Description
Computes a quotient and rounds [half down](https://en.wikipedia.org/wiki/Rounding#Rounding_half_down).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ divideHalfDown(Arithmetic_ dividend, Arithmetic_ divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_half_down.hpp"

int main() {
    std::println("{}", xieite::math::divideHalfDown(5, 2));
    std::println("{}", xieite::math::divideHalfDown(5, -2));
    std::println("{}", xieite::math::divideHalfDown(-5, 2));
    std::println("{}", xieite::math::divideHalfDown(-5, -2));
}
```
Output:
```
2
-3
-3
2
```
