# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideUp\<\>\(\)
Defined in fragment [xieite:math.divideUp](../../../src/math/divide_up.cpp)

&nbsp;

## Description
Computes a quotient and rounds up.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideUp(Arithmetic dividend, std::type_identity_t<Arithmetic> divisor) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::println("{}", xieite::math::divideUp(5, 2));
    std::println("{}", xieite::math::divideUp(5, -2));
    std::println("{}", xieite::math::divideUp(-5, 2));
    std::println("{}", xieite::math::divideUp(-5, -2));
}
```
Output:
```
3
-2
-2
3
```
