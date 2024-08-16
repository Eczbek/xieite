# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideUp\<\>\(\)
Defined in header [<xieite/math/divide_up.hpp>](../../../include/xieite/math/divide_up.hpp)

&nbsp;

## Description
Computes a quotient and rounds up.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]] constexpr Arithmetic divideUp(Arithmetic dividend, Arithmetic divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/divide_up.hpp"

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
