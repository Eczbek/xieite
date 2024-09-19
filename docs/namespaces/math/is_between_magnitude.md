# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:isBetweenMagnitude\<\>\(\)
Defined in fragment [xieite:math.isBetweenMagnitude](../../../src/math/is_between_magnitude.cpp)

&nbsp;

## Description
Checks whether a number is between two limits, where the limits approaching zero or either infinity are optionally inclusive.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool isBetweenMagnitude(Arithmetic value, std::type_identity_t<Arithmetic> limit1, std::type_identity_t<Arithmetic> limit2, bool downInclusive = true, bool upInclusive = true) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

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
