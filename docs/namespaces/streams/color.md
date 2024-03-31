# [xieite](../../xieite.md)\:\:[streams](../../streams.md)\:\:Color \{\}
Defined in header [<xieite/streams/color.hpp>](../../../include/xieite/streams/color.hpp)

&nbsp;

## Description
A simple class for storing an RGB value.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Color {
    std::uint8_t red = 0;
    std::uint8_t green = 0;
    std::uint8_t blue = 0;

    friend constexpr bool operator==(const xieite::streams::Color&, const xieite::streams::Color&) noexcept;

    static constexpr xieite::streams::Color from(std::uint32_t) noexcept;

    constexpr std::uint32_t value() noexcept;
};
```
##### Members
- red
- green
- blue
- alpha
- [operator==\(\)](./structures/color/1/operators/equal.md)
- [from\(\)](./structures/color/1/from.md)
- [value\(\)](./structures/color/1/value.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/color.hpp"

int main() {
    auto color = xieite::streams::Color(255, 127, 0);

    std::println("{} {} {}", color.red, color.green, color.blue);
}
```
Output:
```
255 127 0
```
