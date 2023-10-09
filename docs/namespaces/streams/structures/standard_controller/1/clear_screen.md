# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../standard_controller.md)\:\:clearScreen
Defined in header [<xieite/streams/standard_controller.hpp>](../../../../../../include/xieite/streams/standard_controller.hpp)

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
