# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits_, sign_>](../../../../integer.md)\:\:operator+\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Returns the sum of two integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::Integer<bits_, sign_> operator+() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator+(xieite::math::Integer<bits_, sign_> augend, xieite::math::Integer<bits_, sign_> addend) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    std::println("{}", (xieite::math::Integer<4, false>(9) + 13).data());
}
```
Output:
```
6
```
