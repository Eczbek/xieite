# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:almostEqualSlope\<\>\(\)
Defined in fragment [xieite:math.almostEqualSlope](../../../src/math/almost_equal_slope.cpp)

&nbsp;

## Description
Checks whether two slopes are almost equal or are both infinite.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool almostEqualSlope(Arithmetic value1, std::type_identity_t<Arithmetic> value2) noexcept;
```
Uses `std::numeric_limits<Arithmetic>::epsilon()` scaled by the sum of the arguments.
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool almostEqualSlope(Arithmetic value1, std::type_identity_t<Arithmetic> value2, std::type_identity_t<Arithmetic> epsilon) noexcept;
```
Uses the epsilon argument directly.

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    auto infinity = std::numeric_limits<double>::infinity();

    std::println("{}", xieite::math::almostEqualSlope(infinity, infinity));
}
```
Output:
```
true
```
