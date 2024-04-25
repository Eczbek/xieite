# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits_, sign_>](../../../../integer.md)\:\:operator-=\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Assigns the difference between this integer and another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits_, sign_>& operator-=(xieite::math::Integer<bits_, sign_> subtrahend) noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
constexpr xieite::math::Integer<bits_, sign_>& operator-=(Integral subtrahend) noexcept;
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
