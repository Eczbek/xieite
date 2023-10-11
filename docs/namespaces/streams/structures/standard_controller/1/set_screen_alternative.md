# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setScreenAlternative
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables the alternative screen.

&nbsp;

## Synopses
#### 1)
```cpp
void setScreenAlternative(bool value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/streams/standard_handle.hpp>

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    terminal.setScreenAlternative(true);
    std::cout << "Hello, ";
    terminal.setScreenAlternative(false);
    std::cout << "world!\n";
}
```
Output:
```
world!
```
