# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setScreenAlternate\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables the alternate screen.

&nbsp;

## Synopsis
#### 1)
```cpp
void setScreenAlternate(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setScreenAlternate(true);
    std::print("Hello, ");
    terminal.setScreenAlternate(false);
    std::println("world!");
}
```
Possible output:
```
world!
```
