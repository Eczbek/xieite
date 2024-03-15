# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:sign\(\)
Defined in header [<xieite/math/sign.hpp>](../../../include/xieite/math/sign.hpp)

&nbsp;

## Description
Gets the sign of a number.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]] constexpr int sign(Number value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/sign.hpp"

int main() {
    std::println("{}", xieite::math::sign(418));
    std::println("{}", xieite::math::sign(-903));
    std::println("{}", xieite::math::sign(0));
}
```
Output:
```
1
-1
0
```
