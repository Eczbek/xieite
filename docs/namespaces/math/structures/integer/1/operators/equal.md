# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator==\(\)
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Compares two integers.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(xieite::math::Integer<bits, sign> leftComparand, xieite::math::Integer<bits, sign> rightComparand) noexcept;
```
#### 2)
```cpp
template<std::integral Integral>
[[nodiscard]] friend constexpr bool operator==(xieite::math::Integer<bits, sign> leftComparand, Integral rightComparand) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    std::println("{}", xieite::math::Integer<4, false>(16) == 0);
}
```
Output:
```
true
```
