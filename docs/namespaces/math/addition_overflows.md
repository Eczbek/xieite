# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:additionOverflows
Defined in header [<xieite/math/addition_overflows.hpp"](../../../include/xieite/math/addition_overflows.hpp)

&nbsp;

## Description
Checks if the addition of two values will overflow or underflow their type, or is not representable.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool additionOverflows(const Number value1, const Number value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include "xieite/math/addition_overflows.hpp"

int main() {
    std::cout
        << std::boolalpha
        << xieite::math::additionOverflows<std::uint8_t>(127, 1) << '\n';
}
```
Output:
```
true
```
