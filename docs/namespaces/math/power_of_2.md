# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:powerOf2
Defined in header [<xieite/math/power_of_2.hpp"](../../../include/xieite/math/power_of_2.hpp)

&nbsp;

## Description
Checks that a value is a power of 2.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::unsigned_integral UnsignedInteger>
[[nodiscard]] constexpr bool powerOf2(UnsignedInteger value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/power_of_2.hpp"

int main() {
    std::cout
        << std::boolalpha
        << xieite::math::powerOf2(4) << '\n'
        << xieite::math::powerOf2(0) << '\n';
}
```
Output:
```
true
false
```
