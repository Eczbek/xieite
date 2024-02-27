# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:divideUp
Defined in header [<xieite/math/divide_up.hpp>](../../../include/xieite/math/divide_up.hpp)

&nbsp;

## Description
Computes the value of a division and rounds away from zero.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr Integer divideUp(const Integer dividend, const Integer divisor) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/divide_up.hpp"

int main() {
    std::cout << xieite::math::divideUp(-249, 16) << '\n';
}
```
Output:
```
-16
```
