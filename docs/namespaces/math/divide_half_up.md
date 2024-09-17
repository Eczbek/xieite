# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideHalfUp\<\>\(\)
Defined in fragment [xieite:math.divideHalfUp](../../../src/math/divide_half_up.cpp)

&nbsp;

## Description
Computes a quotient and rounds [half up](https://en.wikipedia.org/wiki/Rounding#Rounding_half_up).

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideHalfUp(Arithmetic dividend, std::common_type_t<Arithmetic> divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::divideHalfUp(5, 2));
    std::println("{}", xieite::math::divideHalfUp(5, -2));
    std::println("{}", xieite::math::divideHalfUp(-5, 2));
    std::println("{}", xieite::math::divideHalfUp(-5, -2));
}
```
Output:
```
3
-2
-2
3
```
