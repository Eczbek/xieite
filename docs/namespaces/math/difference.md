# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:difference
Defined in header [<xieite/math/difference.hpp>](../../../include/xieite/math/difference.hpp)

&nbsp;

## Description
Computes the absolute difference between two values. Handles some edge cases.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number>
[[nodiscard]] constexpr xieite::math::AttemptUnsign<Number> difference(Number value1, Number value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <limits>
#include <xieite/math/difference.hpp>

int main() {
    std::int8_t min = std::numeric_limits<std::int8_t>::min();
    std::int8_t max = std::numeric_limits<std::int8_t>::max();

    std::cout
        << min << '\n'
        << max << '\n'
        << xieite::math::difference(min, max) << '\n';
}
```
Output:
```
-128
127
255
```
