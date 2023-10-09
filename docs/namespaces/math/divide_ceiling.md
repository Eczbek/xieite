# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideCeiling
Defined in header [<xieite/math/divide_ceiling.hpp>](../../../include/xieite/math/divide_ceiling.hpp)

&nbsp;

## Description
Computes the ceiling value of a division.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr Integer divideCeiling(const Integer dividend, const Integer divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/math/divide_ceiling.hpp>

int main() {
    std::cout << xieite::math::divideCeiling(249, 16) << '\n';
}
```
Output:
```
16
```
