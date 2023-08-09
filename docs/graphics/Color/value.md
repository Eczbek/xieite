# [xieite](../../xieite.md)\:\:[graphics](../../graphics.md)\:\:[Color](../Color.md)\:\:value
Defined in header [<xieite/graphics/Color.hpp>](../../../include/xieite/graphics/Color.hpp)

&nbsp;

## Description
Shifts and adds RGBA values together to create a single value.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr std::uint32_t value() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/graphics/Color.hpp>

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
