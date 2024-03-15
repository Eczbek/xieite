# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:splitBoolean\(\)
Defined in header [<xieite/math/split_boolean.hpp>](../../../include/xieite/math/split_boolean.hpp)

&nbsp;

## Description
"Splits" a boolean. `true` remains `1`, but `false` becomes `-1`.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr int splitBoolean(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/split_boolean.hpp"

int main() {
    std::println("{}", xieite::math::splitBoolean(false));
}
```
Output:
```
-1
```
