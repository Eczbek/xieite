# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:almostEqualSlope\<\>\(\)
Defined in header [<xieite/math/almost_equal_slope.hpp>](../../../include/xieite/math/almost_equal_slope.hpp)

&nbsp;

## Description
Checks whether two slopes are almost equal or are both infinite.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr bool almostEqualSlope(Arithmetic_ value1, Arithmetic_ value2) noexcept;
```
Uses `std::numeric_limits<Arithmetic_>::epsilon()` scaled by the sum of the arguments.
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr bool almostEqualSlope(Arithmetic_ value1, Arithmetic_ value2, Arithmetic_ epsilon) noexcept;
```
Uses the epsilon argument directly.

&nbsp;

## Example
```cpp
#include <limits>
#include <print>
#include "xieite/math/almost_equal_slope.hpp"

int main() {
    auto infinity = std::numeric_limits<double>::infinity();

    std::println("{}", xieite::math::almostEqualSlope(infinity, infinity));
}
```
Output:
```
true
```
