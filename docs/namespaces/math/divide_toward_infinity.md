# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideTowardInfinity\<\>\(\)
Defined in header [<xieite/math/divide_toward_infinity.hpp>](../../../include/xieite/math/divide_toward_infinity.hpp)

&nbsp;

## Description
Computes a quotient and rounds toward infinity.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideTowardInfinity(Arithmetic dividend, Arithmetic divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_toward_infinity.hpp"

int main() {
    std::println("{}", xieite::math::divideTowardInfinity(5, 2));
    std::println("{}", xieite::math::divideTowardInfinity(5, -2));
    std::println("{}", xieite::math::divideTowardInfinity(-5, 2));
    std::println("{}", xieite::math::divideTowardInfinity(-5, -2));
}
```
Output:
```
3
-3
-3
3
```
