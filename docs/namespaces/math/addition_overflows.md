# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:additionOverflows\(\)
Defined in header [<xieite/math/addition_overflows.hpp>](../../../include/xieite/math/addition_overflows.hpp)

&nbsp;

## Description
Checks if the addition of two values will overflow or underflow their type (therefore causing undefined behavior with signed integers), or is not representable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr bool additionOverflows(Number augend, Number addend) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/math/addition_overflows.hpp"

int main() {
    std::print("{}", xieite::math::additionOverflows<std::int8_t>(127, 1));
}
```
Output:
```
true
```
