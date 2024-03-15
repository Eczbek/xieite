# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator-\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Returns the difference between two integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr xieite::math::Integer<bits, sign> operator-() const noexcept;
```
#### 2)
```cpp
[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator-(xieite::math::Integer<bits, sign> minuend, xieite::math::Integer<bits, sign> subtrahend) noexcept;
```
#### 3)
```cpp
template<std::integral Integer>
[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator-(xieite::math::Integer<bits, sign> minuend, Integer subtrahend) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    std::println("{}", (xieite::math::Integer<4, false>(9) - 3).data());
}
```
Output:
```
6
```
