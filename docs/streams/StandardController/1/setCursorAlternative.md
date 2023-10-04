# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:[StandardController](../../StandardController.md)\:\:setCursorAlternative
Defined in header [<xieite/streams/StandardController.hpp>](../../../../include/xieite/streams/StandardController.hpp)

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
#include <xieite/system/terminal.hpp>

int main() {
    xieite::system::terminal.setCursorAlternative(true);
    std::cout << "Hello, ";
    xieite::system::terminal.setCursorAlternative(false);
    std::cout << "world!\n";
}
```
Output:
```
world!
```
