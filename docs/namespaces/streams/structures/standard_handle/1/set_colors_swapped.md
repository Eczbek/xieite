# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setColorsSwapped\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables the swapping of foreground and background colors.

&nbsp;

## Synopsis
#### 1)
```cpp
void setColorsSwapped(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/color.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setForegroundColor(xieite::streams::Color(255, 0, 0));
    terminal.setBackgroundColor(xieite::streams::Color(0, 0, 255));

    std::print("Hello, ");

    terminal.setColorsSwapped(true);

    std::println("world!");
}
```
Possible output:

![image](./set_colors_swapped.png)
