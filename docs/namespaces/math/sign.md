# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:sign
Defined in header [<xieite/math/sign.hpp>](../../../include/xieite/math/sign.hpp)

&nbsp;

## Description
Gets the sign of a number.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number>
[[nodiscard]] constexpr int sign(Number value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/sign.hpp>

int main() {
    std::cout
        << xieite::math::sign(418) << '\n'
        << xieite::math::sign(-903) << '\n'
        << xieite::math::sign(0) << '\n';
}
```
Output:
```
1
-1
0
```
