# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isBetweenFixed\<\>\(\)
Defined in fragment [xieite:math.isBetweenFixed](../../../src/math/is_between_fixed.cpp)

&nbsp;

## Description
Checks whether a number is between two limits, where the floor and ceiling limits are optionally inclusive.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool isBetweenFixed(Arithmetic value, Arithmetic limit1, Arithmetic limit2, bool floorInclusive = true, bool ceilingInclusive = true) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
