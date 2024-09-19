# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:almostEqual\<\>\(\)
Defined in fragment [xieite:math.almostEqual](../../../src/math/almost_equal.cpp)

&nbsp;

## Description
Checks if two values are almost equal.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool almostEqual(Arithmetic value1, std::type_identity_t<Arithmetic> value2) noexcept;
```
Uses `std::numeric_limits<Arithmetic>::epsilon()` scaled by the sum of the arguments.
#### 2)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr bool almostEqual(Arithmetic value1, std::type_identity_t<Arithmetic> value2, std::type_identity_t<Arithmetic> epsilon) noexcept;
```
Uses the epsilon argument directly.

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    double a = 0.3;
    double b = 0.1 + 0.2; // 0.30000000000000004

    std::println("{}", a == b);
    std::println("{}", xieite::math::almostEqual(a, b));
}
```
Output:
```
false
true
```
