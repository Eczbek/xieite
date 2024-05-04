# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isBetweenFixed\<\>\(\)
Defined in header [<xieite/math/is_between_fixed.hpp>](../../../include/xieite/math/is_between_fixed.hpp)

&nbsp;

## Description
Checks whether a number is between two limits, where the floor and ceiling limits are optionally inclusive.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic_>
[[nodiscard]] constexpr bool isBetweenFixed(Arithmetic_ value, Arithmetic_ limit1, Arithmetic_ limit2, bool floorInclusive = true, bool ceilingInclusive = true) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/is_between_fixed.hpp"

int main() {
    std::println("{}", xieite::math::isBetweenFixed(17, 10, 20));
    std::println("{}", xieite::math::isBetweenFixed(-5, 0, -5));
    std::println("{}", xieite::math::isBetweenFixed(-5, 0, -5, false));
}
```
Output:
```
true
true
false
```
