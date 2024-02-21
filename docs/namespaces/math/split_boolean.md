# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:splitBoolean
Defined in header [<xieite/math/split_boolean.hpp"](../../../include/xieite/math/split_boolean.hpp)

&nbsp;

## Description
"Splits" a boolean. `true` stays `1`, but `false` becomes `-1`.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr int splitBoolean(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/split_boolean.hpp"

int main() {
    std::cout << xieite::math::splitBoolean(false) << '\n';
}
```
Output:
```
-1
```
