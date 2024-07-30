# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[Color](../../../color.md)\:\:from\(\)
Defined in header [<xieite/streams/color.hpp>](../../../../../../include/xieite/streams/color.hpp)

&nbsp;

## Description
Constructs a `xieite::streams::Color` from a single value containing all three RGB values.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] static constexpr xieite::streams::Color from(std::uint32_t value) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/color.hpp"

int main() {
    auto color = xieite::streams::Color::from(0xFF7F00);

    std::println("{} {} {}", color.red, color.green, color.blue);
}
```
Output:
```
255 127 0
```
