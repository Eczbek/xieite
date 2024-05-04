# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:multiplicationOverflows\<\>\(\)
Defined in header [<xieite/math/multiplication_overflows.hpp>](../../../include/xieite/math/multiplication_overflows.hpp)

&nbsp;

## Description
Checks if the multiplication of two values will overflow or underflow their type, or is not representable.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr bool multiplicationOverflows(Arithmetic_ multiplier, Arithmetic_ multiplicand) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/math/multiplication_overflows.hpp"

int main() {
    std::println("{}", xieite::math::multiplicationOverflows<std::uint8_t>(99, 99));
}
```
Output:
```
true
```
