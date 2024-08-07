# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:sign\<\>\(\)
Defined in header [<xieite/math/sign.hpp>](../../../include/xieite/math/sign.hpp)

&nbsp;

## Description
Gets the sign of a number or the sign of the product of several numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic First_, std::same_as<First_>... Rest_>
[[nodiscard]] constexpr int sign(First_ first, Rest_... rest) noexcept;
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
