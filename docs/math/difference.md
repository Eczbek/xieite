# [xieite](../xieite.md)\:\:[math](../math.md)\:\:difference
Defined in header [<xieite/math/difference.hpp>](../../include/xieite/math/difference.hpp)

&nbsp;

## Description
Calculates the absolute difference between two values. Handles some edge cases.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]]
constexpr std::make_unsigned<Integer> difference(Integer a, Integer b) noexcept;
```
#### 2)
```cpp
template<std::floating_point Floating>
[[nodiscard]]
constexpr Floating difference(Floating a, Floating b) noexcept;
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
