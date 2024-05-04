# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideUp\<\>\(\)
Defined in header [<xieite/math/divide_up.hpp>](../../../include/xieite/math/divide_up.hpp)

&nbsp;

## Description
Computes the value of a division and rounds away from zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr Integral_ divideUp(Integral_ dividend, Integral_ divisor) noexcept;
```
#### 2)
```cpp
template<std::floating_point Fractional_>
[[nodiscard]] constexpr Fractional_ divideUp(Fractional_ dividend, Fractional_ divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_up.hpp"

int main() {
    std::println("{}", xieite::math::divideUp(-249, 16));
}
```
Output:
```
-16
```
