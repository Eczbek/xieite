# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:almostEqual
Defined in header [<xieite/math/almost_equal.hpp>](../../../include/xieite/math/almost_equal.hpp)

&nbsp;

## Description
Checks if two values are almost equal.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Number Number2>
[[nodiscard]] constexpr bool almostEqual(Number1 value1, Number2 value2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/almost_equal.hpp>

int main() {
    double a = 0.3;
    double b = 0.1 + 0.2;

    std::cout
        << std::boolalpha
        << (a == b) << '\n'
        << xieite::math::almostEqual(a, b) << '\n';
}
```
Output:
```
false
true
```
