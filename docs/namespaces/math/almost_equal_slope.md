# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:almostEqualSlope\<\>\(\)
Defined in header [<xieite/math/almost_equal_slope.hpp>](../../../include/xieite/math/almost_equal_slope.hpp)

&nbsp;

## Description
Checks whether two slopes are almost equal or are both infinite.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool almostEqualSlope(Arithmetic value1, Arithmetic value2) noexcept;
```
Uses `std::numeric_limits<Arithmetic>::epsilon()` scaled by the sum of the arguments.
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool almostEqualSlope(Arithmetic value1, Arithmetic value2, Arithmetic epsilon) noexcept;
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
