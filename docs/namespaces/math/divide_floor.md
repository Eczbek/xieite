# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideFloor
Defined in header [<xieite/math/divide_floor.hpp>](../../../include/xieite/math/divide_floor.hpp)

&nbsp;

## Description
Computes the floor value of a division.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr Integer divideFloor(const Integer dividend, const Integer divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/divide_floor.hpp"

int main() {
    std::cout << xieite::math::divideFloor(249, 16) << '\n';
}
```
Output:
```
15
```
