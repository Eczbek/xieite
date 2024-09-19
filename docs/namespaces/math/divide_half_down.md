# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideHalfDown\<\>\(\)
Defined in fragment [xieite:math.divideHalfDown](../../../src/math/divide_half_down.cpp)

&nbsp;

## Description
Computes a quotient and rounds [half down](https://en.wikipedia.org/wiki/Rounding#Rounding_half_down).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideHalfDown(Arithmetic dividend, std::type_identity_t<Arithmetic> divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::divideHalfDown(5, 2));
    std::println("{}", xieite::math::divideHalfDown(5, -2));
    std::println("{}", xieite::math::divideHalfDown(-5, 2));
    std::println("{}", xieite::math::divideHalfDown(-5, -2));
}
```
Output:
```
2
-3
-3
2
```
