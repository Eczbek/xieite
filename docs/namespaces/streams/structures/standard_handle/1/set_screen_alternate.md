# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setScreenAlternate
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables the Alternate screen.

&nbsp;

## Synopsis
#### 1)
```cpp
void setScreenAlternate(bool value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    terminal.setScreenAlternate(true);
    std::cout << "Hello, ";
    terminal.setScreenAlternate(false);
    std::cout << "world!\n";
}
```
Output:
```
world!
```
