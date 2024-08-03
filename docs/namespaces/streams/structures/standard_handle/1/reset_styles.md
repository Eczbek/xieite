# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:resetStyles\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Resets all text and color effects. Automatically called upon destruction.

&nbsp;

## Synopsis
#### 1)
```cpp
void resetStyles() noexcept;
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

    terminal.setTextBold(true);
    terminal.setTextItalic(true);
    terminal.setForegroundColor(xieite::streams::Color(255, 0, 0));
    terminal.setBackgroundColor(xieite::streams::Color(0, 0, 255));
    terminal.setColorsSwapped(true);
    std::print("Hello, ");

    terminal.resetStyles();

    std::println("world!");
}
```
Possible output:

![image](./reset_styles.png)
