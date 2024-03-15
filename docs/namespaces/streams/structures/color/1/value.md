# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Color](../../../color.md)\:\:value
Defined in header [<xieite/streams/color.hpp>](../../../../../../include/xieite/streams/color.hpp)

&nbsp;

## Description
Shifts and adds RGBA values together to create a single value.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::uint32_t value() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/stringify.hpp"
#include "xieite/streams/color.hpp"

int main() {
    xieite::streams::Color color(255, 127, 0);

    std::println("{}", xieite::math::stringify(color.value(), 16));
}
```
Output:
```
ff7f00ff
```
