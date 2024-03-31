# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:resetBackgroundColor\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Resets the text highlight color to default.

&nbsp;

## Synopsis
#### 1)
```cpp
void resetBackgroundColor() noexcept;
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

    terminal.setBackgroundColor(xieite::streams::Color(0, 0, 255));
    std::print("Hello, ");
    terminal.resetBackgroundColor();
    std::println("world!");
}
```
Possible output:

![image](./reset_background_color.png)
