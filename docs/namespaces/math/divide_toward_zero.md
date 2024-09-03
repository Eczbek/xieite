# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideTowardZero\<\>\(\)
Defined in fragment [xieite:math.divideTowardZero](../../../src/math/divide_toward_zero.cpp)

&nbsp;

## Description
Computes a quotient and rounds toward zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideTowardZero(Arithmetic dividend, Arithmetic divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::divideTowardZero(5, 2));
    std::println("{}", xieite::math::divideTowardZero(5, -2));
    std::println("{}", xieite::math::divideTowardZero(-5, 2));
    std::println("{}", xieite::math::divideTowardZero(-5, -2));
}
```
Output:
```
2
-2
-2
2
```
