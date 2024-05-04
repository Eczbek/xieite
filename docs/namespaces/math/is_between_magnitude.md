# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isBetweenMagnitude\<\>\(\)
Defined in header [<xieite/math/is_between_magnitude.hpp>](../../../include/xieite/math/is_between_magnitude.hpp)

&nbsp;

## Description
Checks whether a number is between two limits, where the limits approaching zero or either infinity are optionally inclusive.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr bool isBetweenMagnitude(Arithmetic_ value, Arithmetic_ limit1, Arithmetic_ limit2, bool downInclusive = true, bool upInclusive = true) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/is_between_magnitude.hpp"

int main() {
    std::println("{}", xieite::math::isBetweenMagnitude(0, 0, 5));
    std::println("{}", xieite::math::isBetweenMagnitude(0, 0, 5, false));
    std::println("{}", xieite::math::isBetweenMagnitude(-5, -5, 0, true, false));
}
```
Output:
```
true
false
false
```
