# [xieite](../../../xieite.md)\:\:[streams](../../../streams.md)\:\:[StandardController](../../StandardController.md)\:\:clearScreen
Defined in header [<xieite/streams/StandardController.hpp>](../../../../include/xieite/streams/StandardController.hpp)

&nbsp;

## Description
Clears the entire screen.

&nbsp;

## Synopses
#### 1)
```cpp
void clearScreen() const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
    std::cout << "Hello, world!\n";

    xieite::system::terminal.clearScreen();
}
```
Output:
```
```
