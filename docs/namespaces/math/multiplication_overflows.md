# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:multiplicationOverflows
Defined in header [<xieite/math/multiplication_overflows.hpp"](../../../include/xieite/math/multiplication_overflows.hpp)

&nbsp;

## Description
Checks if the multiplication of two values will overflow or underflow their type, or is not representable.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool multiplicationOverflows(const Number value1, const Number value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include "xieite/math/multiplication_overflows.hpp"

int main() {
    std::cout
        << std::boolalpha
        << xieite::math::multiplicationOverflows<std::uint8_t>(99, 99) << '\n';
}
```
Output:
```
true
```
