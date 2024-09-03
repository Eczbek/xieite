# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideTowardInfinity\<\>\(\)
Defined in fragment [xieite:math.divideTowardInfinity](../../../src/math/divide_toward_infinity.cpp)

&nbsp;

## Description
Computes a quotient and rounds toward infinity.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideTowardInfinity(Arithmetic dividend, Arithmetic divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::divideTowardInfinity(5, 2));
    std::println("{}", xieite::math::divideTowardInfinity(5, -2));
    std::println("{}", xieite::math::divideTowardInfinity(-5, 2));
    std::println("{}", xieite::math::divideTowardInfinity(-5, -2));
}
```
Output:
```
3
-3
-3
3
```
