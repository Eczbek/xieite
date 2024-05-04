# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:difference\<\>\(\)
Defined in header [<xieite/math/difference.hpp>](../../../include/xieite/math/difference.hpp)

&nbsp;

## Description
Computes the absolute difference between two values. Handles some edge cases.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr xieite::types::TryUnsigned<Arithmetic_> difference(Arithmetic_ value1, Arithmetic_ value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <limits>
#include <print>
#include "xieite/math/difference.hpp"

int main() {
    std::int8_t min = std::numeric_limits<std::int8_t>::min();
    std::int8_t max = std::numeric_limits<std::int8_t>::max();

    std::println("{}", min);
    std::println("{}", max);
    std::println("{}", xieite::math::difference(min, max));
}
```
Output:
```
-128
127
255
```
