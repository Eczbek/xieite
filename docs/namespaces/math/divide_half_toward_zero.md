# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideHalfTowardZero\<\>\(\)
Defined in fragment [xieite:math.divideHalfTowardZero](../../../src/math/divide_half_toward_zero.cpp)

&nbsp;

## Description
Computes a quotient and rounds [half toward zero](https://en.wikipedia.org/wiki/Rounding#Rounding_half_toward_zero).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideHalfTowardZero(Arithmetic dividend, std::type_identity_t<Arithmetic> divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::divideHalfTowardZero(5, 2));
    std::println("{}", xieite::math::divideHalfTowardZero(5, -2));
    std::println("{}", xieite::math::divideHalfTowardZero(-5, 2));
    std::println("{}", xieite::math::divideHalfTowardZero(-5, -2));
}
```
Output:
```
2
-2
-2
2
```
