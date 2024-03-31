# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setTextUnderlined\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables text <u>underlining</u>.

&nbsp;

## Synopsis
#### 1)
```cpp
void setTextUnderlined(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setTextUnderlined(true);

    std::println("Hello, world!");
}
```
Possible output:

![image](./set_text_underlined.md)
