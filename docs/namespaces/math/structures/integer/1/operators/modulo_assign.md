# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator%=\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Assigns the remainder after division of this integer with another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits, sign>& operator%=(xieite::math::Integer<bits, sign> divisor) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::Integer<bits, sign>& operator%=(Integer divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    xieite::math::Integer<4, false> integer = 9;

    integer %= 3;

    std::println("{}", integer.data());
}
```
Output:
```
0
```
