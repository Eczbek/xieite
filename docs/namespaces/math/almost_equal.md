# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:almostEqual\(\)
Defined in header [<xieite/math/almost_equal.hpp>](../../../include/xieite/math/almost_equal.hpp)

&nbsp;

## Description
Checks if two values are almost equal.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool almostEqual(Number value1, Number value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/almost_equal.hpp"

int main() {
    double a = 0.3;
    double b = 0.1 + 0.2; // 0.30000000000000004

    std::println("{}", a == b);
    std::println("{}", xieite::math::almostEqual(a, b));
}
```
Output:
```
false
true
```
