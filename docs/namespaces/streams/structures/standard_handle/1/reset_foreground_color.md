# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:resetForegroundColor\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Resets the text color to default.

&nbsp;

## Synopsis
#### 1)
```cpp
void resetForegroundColor() noexcept;
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

    terminal.setForegroundColor(xieite::streams::Color<3>(255, 0, 0));
    std::print("Hello, ");
    terminal.resetForegroundColor();
    std::println("world!");
}
```
Possible output:

![image](./reset_foreground_color.png)
