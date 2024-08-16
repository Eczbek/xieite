# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideTowardZero\<\>\(\)
Defined in header [<xieite/math/divide_toward_zero.hpp>](../../../include/xieite/math/divide_toward_zero.hpp)

&nbsp;

## Description
Computes a quotient and rounds toward zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideTowardZero(Arithmetic dividend, Arithmetic divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_toward_zero.hpp"

int main() {
    std::println("{}", xieite::math::divideTowardZero(5, 2));
    std::println("{}", xieite::math::divideTowardZero(5, -2));
    std::println("{}", xieite::math::divideTowardZero(-5, 2));
    std::println("{}", xieite::math::divideTowardZero(-5, -2));
}
```
Output:
```
2
-2
-2
2
```
