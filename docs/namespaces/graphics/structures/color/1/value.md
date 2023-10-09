# [xieite](../../../../../xieite.md)\:\:[graphics](../../../../../graphics.md)\:\:[Color](../../../color.md)\:\:value
Defined in header [<xieite/graphics/color.hpp>](../../../../../../include/xieite/graphics/color.hpp)

&nbsp;

## Description
Shifts and adds RGBA values together to create a single value.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::uint32_t value() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/graphics/color.hpp>

int main() {
    xieite::graphics::Color color(255, 127, 0);

    std::cout
        << std::hex
        << color.value() << '\n';
}
```
Output:
```
ff7f00ff
```
