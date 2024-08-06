# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideDown\<\>\(\)
Defined in header [<xieite/math/divide_down.hpp>](../../../include/xieite/math/divide_down.hpp)

&nbsp;

## Description
Computes a quotient and rounds down.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr Arithmetic_ divideDown(Arithmetic_ dividend, Arithmetic_ divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_down.hpp"

int main() {
    std::println("{}", xieite::math::divideDown(5, 2));
    std::println("{}", xieite::math::divideDown(5, -2));
    std::println("{}", xieite::math::divideDown(-5, 2));
    std::println("{}", xieite::math::divideDown(-5, -2));
}
```
Output:
```
2
-3
-3
2
```
