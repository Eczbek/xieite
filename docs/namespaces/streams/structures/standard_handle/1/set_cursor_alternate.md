# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorAlternate\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables the alternate cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
void setCursorAlternate(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setCursorAlternate(true);
    std::print("Hello there");
    terminal.setCursorAlternate(false);
    std::println("world!");
}
```
Possible output:
```
world!there
```
