# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideFloor\<\>\(\)
Defined in header [<xieite/math/divide_floor.hpp>](../../../include/xieite/math/divide_floor.hpp)

&nbsp;

## Description
Computes the floor value of a division.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr Integral_ divideFloor(Integral_ dividend, Integral_ divisor) noexcept;
```
#### 2)
```cpp
template<std::floating_point Fractional_>
[[nodiscard]] constexpr Fractional_ divideFloor(Fractional_ dividend, Fractional_ divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_floor.hpp"

int main() {
    std::println("{}", xieite::math::divideFloor(249, 16));
}
```
Output:
```
15
```
