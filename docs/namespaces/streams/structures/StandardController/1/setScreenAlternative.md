# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../StandardController.md)\:\:setScreenAlternative
Defined in header [<xieite/streams/StandardController.hpp>](../../../../../../include/xieite/streams/StandardController.hpp)

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
#include <xieite/system/terminal.hpp>

int main() {
    xieite::system::terminal.setScreenAlternative(true);
    std::cout << "Hello, ";
    xieite::system::terminal.setScreenAlternative(false);
    std::cout << "world!\n";
}
```
Output:
```
world!
```
