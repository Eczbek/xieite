# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits_, sign_>](../../../../integer.md)\:\:operator++\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Increments a integer.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr xieite::math::Integer<bits_, sign_>& operator++() noexcept;
```
#### 2)
```cpp
constexpr xieite::math::Integer<bits_, sign_>& operator++(int) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    xieite::math::Integer<4, false> integer = 7;

    std::println("{}", (++integer).data());
}
```
Output:
```
8
```
