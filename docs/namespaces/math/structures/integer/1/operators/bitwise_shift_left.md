# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator<<\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Returns this integer bitwise shifted to the left.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator<<(xieite::math::Integer<bits, sign> leftOperand, xieite::math::Integer<bits, sign> rightOperand) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator<<(xieite::math::Integer<bits, sign> leftOperand, Integer rightOperand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    std::println("{}", (xieite::math::Integer<4, false>(9) << 3).data());
}
```
Output:
```
8
```
