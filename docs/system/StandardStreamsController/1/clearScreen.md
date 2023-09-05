# [xieite](../../../xieite.md)\:\:[system](../../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../../StandardStreamsController.md)\:\:clearScreen
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Clears the entire screen.

&nbsp;

## Synopses
#### 1)
```cpp
void clearScreen() noexcept;
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
