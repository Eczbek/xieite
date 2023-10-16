# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:subtractionOverflows
Defined in header [<xieite/math/subtraction_overflows.hpp>](../../../include/xieite/math/subtraction_overflows.hpp)

&nbsp;

## Description
Checks if the subtraction of two values will overflow or underflow their type.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr bool subtractionOverflows(const Integer value1, const Integer value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <xieite/math/subtraction_overflows.hpp>

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
