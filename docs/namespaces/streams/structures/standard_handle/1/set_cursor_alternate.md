# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorAlternate
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables the Alternate cursor. The Alternate cursor starts at the original cursor's position.

&nbsp;

## Synopsis
#### 1)
```cpp
void setCursorAlternate(bool value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    terminal.setCursorAlternate(true);
    std::print("Hello, ");
    terminal.setCursorAlternate(false);
    std::println("world!");
}
```
Output:
```
world!
```
