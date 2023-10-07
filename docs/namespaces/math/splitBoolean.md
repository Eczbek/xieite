# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:splitBoolean
Defined in header [<xieite/math/splitBoolean.hpp>](../../../include/xieite/math/splitBoolean.hpp)

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
#include <xieite/math/splitBoolean.hpp>

int main() {
    std::cout << xieite::math::splitBoolean(false) << '\n';
}
```
Output:
```
-1
```
