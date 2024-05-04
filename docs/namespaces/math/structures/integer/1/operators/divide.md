# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits_, sign_>](../../../../integer.md)\:\:operator/\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Returns the quotient of two integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator/(xieite::math::Integer<bits_, sign_> dividend, xieite::math::Integer<bits_, sign_> divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    std::println("{}", (xieite::math::Integer<4, false>(9) / 3).data());
}
```
Output:
```
3
```
