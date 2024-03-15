# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator--\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Decrements a integer.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits, sign>& operator--() noexcept;
```
#### 2)
```cpp
constexpr xieite::math::Integer<bits, sign>& operator--(int) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    xieite::math::Integer<4, false> integer = 7;

    std::println("{}", (--integer).data());
}
```
Output:
```
6
```
