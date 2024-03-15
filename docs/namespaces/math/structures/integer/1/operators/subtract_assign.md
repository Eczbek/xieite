# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator-=\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Assigns the difference between this integer and another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits, sign>& operator-=(xieite::math::Integer<bits, sign> subtrahend) noexcept;
```
#### 2)
```cpp
template<std::integral Integer>
constexpr xieite::math::Integer<bits, sign>& operator-=(Integer subtrahend) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    xieite::math::Integer<4, false> integer = 9;

    integer -= 3;

    std::println("{}", integer.data());
}
```
Output:
```
6
```
