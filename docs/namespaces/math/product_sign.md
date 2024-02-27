# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:sign
Defined in header [<xieite/math/sign.hpp>](../../../include/xieite/math/sign.hpp)

&nbsp;

## Description
Gets the sign of the product of multiple numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Numbers>
[[nodiscard]] constexpr int productSign(Numbers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/sign.hpp"

int main() {
    std::cout << xieite::math::productSign(2, -4, -8) << '\n';
}
```
Output:
```
1
```
