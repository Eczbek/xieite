# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideHalfTowardInfinity\<\>\(\)
Defined in fragment [xieite:math.divideHalfTowardInfinity](../../../src/math/divide_half_toward_infinity.cpp)

&nbsp;

## Description
Computes a quotient and rounds [half toward infinity](https://en.wikipedia.org/wiki/Rounding#Rounding_half_away_from_zero).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideHalfTowardInfinity(Arithmetic dividend, std::type_identity_t<Arithmetic> divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::divideHalfTowardInfinity(5, 2));
    std::println("{}", xieite::math::divideHalfTowardInfinity(5, -2));
    std::println("{}", xieite::math::divideHalfTowardInfinity(-5, 2));
    std::println("{}", xieite::math::divideHalfTowardInfinity(-5, -2));
}
```
Output:
```
3
-3
-3
3
```
