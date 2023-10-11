# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorAlternative
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables the alternative cursor. The alternative cursor starts at the original cursor's position.

&nbsp;

## Synopses
#### 1)
```cpp
void setCursorAlternative(bool value) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/streams/standard_handle.hpp>

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    terminal.setCursorAlternative(true);
    std::cout << "Hello, ";
    terminal.setCursorAlternative(false);
    std::cout << "world!\n";
}
```
Output:
```
world!
```
