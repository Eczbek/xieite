# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideHalfUp\<\>\(\)
Defined in header [<xieite/math/divide_half_up.hpp>](../../../include/xieite/math/divide_half_up.hpp)

&nbsp;

## Description
Computes a quotient and rounds [half up](https://en.wikipedia.org/wiki/Rounding#Rounding_half_up).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideHalfUp(Arithmetic dividend, Arithmetic divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_half_up.hpp"

int main() {
    std::println("{}", xieite::math::divideHalfUp(5, 2));
    std::println("{}", xieite::math::divideHalfUp(5, -2));
    std::println("{}", xieite::math::divideHalfUp(-5, 2));
    std::println("{}", xieite::math::divideHalfUp(-5, -2));
}
```
Output:
```
3
-2
-2
3
```
