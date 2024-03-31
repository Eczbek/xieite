# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideDown\(\)
Defined in header [<xieite/math/divide_down.hpp>](../../../include/xieite/math/divide_down.hpp)

&nbsp;

## Description
Computes the value of a division and rounds toward zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr Integral divideDown(Integral dividend, Integral divisor) noexcept;
```
#### 2)
```cpp
template<std::floating_point Fractional>
[[nodiscard]] constexpr Fractional divideDown(Fractional dividend, Fractional divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_down.hpp"

int main() {
    std::println("{}", xieite::math::divideDown(-249, 16));
}
```
Output:
```
-15
```
