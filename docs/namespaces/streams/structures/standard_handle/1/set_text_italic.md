# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setTextItalic\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables *italic* text.

&nbsp;

## Synopsis
#### 1)
```cpp
void setTextItalic(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setTextItalic(true);

    std::println("Hello, world!");
}
```
Possible output:

![image](./set_text_italic.md)
