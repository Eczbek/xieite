# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits_, sign_>](../../../../integer.md)\:\:operator|=\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Assigns the bitwise OR result of this integer with another.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits_, sign_>& operator|=(xieite::math::Integer<bits_, sign_> operand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
constexpr xieite::math::Integer<bits_, sign_>& operator|=(Integral operand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    xieite::math::Integer<4, false> integer = 9;

    integer |= 3;

    std::println("{}", integer.data());
}
```
Output:
```
11
```
