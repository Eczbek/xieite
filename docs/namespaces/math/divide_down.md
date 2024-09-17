# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideDown\<\>\(\)
Defined in fragment [xieite:math.divideDown](../../../src/math/divide_down.cpp)

&nbsp;

## Description
Computes a quotient and rounds down.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideDown(Arithmetic dividend, std::common_type_t<Arithmetic> divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::divideDown(5, 2));
    std::println("{}", xieite::math::divideDown(5, -2));
    std::println("{}", xieite::math::divideDown(-5, 2));
    std::println("{}", xieite::math::divideDown(-5, -2));
}
```
Output:
```
2
-3
-3
2
```
