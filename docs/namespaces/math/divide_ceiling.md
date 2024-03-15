# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideCeiling\(\)
Defined in header [<xieite/math/divide_ceiling.hpp>](../../../include/xieite/math/divide_ceiling.hpp)

&nbsp;

## Description
Computes the ceiling value of a division.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr Integer divideCeiling(Integer dividend, Integer divisor) noexcept;
```
#### 2)
```cpp
template<std::floating_point FloatingPoint>
[[nodiscard]] constexpr FloatingPoint divideCeiling(FloatingPoint dividend, FloatingPoint divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_ceiling.hpp"

int main() {
    std::println("{}", xieite::math::divideCeiling(249, 16));
}
```
Output:
```
16
```
