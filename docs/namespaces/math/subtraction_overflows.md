# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:subtractionOverflows
Defined in header [<xieite/math/subtraction_overflows.hpp>](../../../include/xieite/math/subtraction_overflows.hpp)

&nbsp;

## Description
Checks if the subtraction of two values will overflow or underflow their type, or is not representable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool subtractionOverflows(const Number value1, const Number value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include "xieite/math/subtraction_overflows.hpp"

int main() {
    std::cout
        << std::boolalpha
        << xieite::math::subtractionOverflows<std::uint8_t>(4, 90) << '\n';
}
```
Output:
```
true
```
