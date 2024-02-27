# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideDown
Defined in header [<xieite/math/divide_down.hpp>](../../../include/xieite/math/divide_down.hpp)

&nbsp;

## Description
Computes the value of a division and rounds toward zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr Integer divideDown(const Integer dividend, const Integer divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/divide_down.hpp"

int main() {
    std::cout << xieite::math::divideDown(-249, 16) << '\n';
}
```
Output:
```
-15
```
