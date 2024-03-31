# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setTextBlinking\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables text blinking.

&nbsp;

## Synopsis
#### 1)
```cpp
void setTextBlinking(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setTextBlinking(true);

    std::println("Hello, world!");
}
```
Possible output:

![image](./set_text_blinking.gif)
