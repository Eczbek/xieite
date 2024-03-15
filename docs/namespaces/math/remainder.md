# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:remainder\(\)
Defined in header [<xieite/math/remainder.hpp>](../../../include/xieite/math/remainder.hpp)

&nbsp;

## Description
Computes the remainder after division.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr Integer remainder(Integer dividend, Integer divisor) noexcept;
```
Uses `%`.
#### 2)
```cpp
template<std::floating_point FloatingPoint>
[[nodiscard]] constexpr FloatingPoint remainder(FloatingPoint dividend, FloatingPoint divisor) noexcept;
```
Uses `std::fmod`.

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/remainder.hpp"

int main() {
    std::println("{}", xieite::math::remainder(-21, 4));
}
```
Output:
```
-1
```
