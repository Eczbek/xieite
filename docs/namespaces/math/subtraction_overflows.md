# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:subtractionOverflows\(\)
Defined in header [<xieite/math/subtraction_overflows.hpp>](../../../include/xieite/math/subtraction_overflows.hpp)

&nbsp;

## Description
Checks if the subtraction of two values will overflow or underflow their type, or is not representable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool subtractionOverflows(Number minuend, Number subtrahend) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/math/subtraction_overflows.hpp"

int main() {
    std::println("{}", xieite::math::subtractionOverflows<std::uint8_t>(4, 90));
}
```
Output:
```
true
```
