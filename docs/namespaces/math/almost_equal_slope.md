# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:almostEqualSlope\(\)
Defined in header [<xieite/math/almost_equal_slope.hpp>](../../../include/xieite/math/almost_equal_slope.hpp)

&nbsp;

## Description
Checks whether two slopes are almost equal or are both infinite.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool almostEqualSlope(Number value1, Number value2) noexcept;
```

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
