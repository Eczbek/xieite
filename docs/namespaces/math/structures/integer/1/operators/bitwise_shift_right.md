# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits_, sign_>](../../../../integer.md)\:\:operator\>\>\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Returns this integer bitwise shifted to the right.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator>>(xieite::math::Integer<bits_, sign_> leftOperand, xieite::math::Integer<bits_, sign_> rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    std::println("{}", (xieite::math::Integer<4, false>(9) >> 3).data());
}
```
Output:
```
1
```
