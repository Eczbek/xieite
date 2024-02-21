# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:reverse
Defined in header [<xieite/math/reverse.hpp"](../../../include/xieite/math/reverse.hpp)

&nbsp;

## Description
Reverses an integral of any base.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer>
[[nodiscard]] constexpr Integer reverse(Integer value, std::size_t base = 10) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/reverse.hpp"

int main() {
    std::cout << xieite::math::reverse(12345) << '\n';
}
```
Output:
```
54321
```
