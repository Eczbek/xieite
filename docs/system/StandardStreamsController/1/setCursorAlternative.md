# [xieite](../../../xieite.md)\:\:[system](../../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../../StandardStreamsController.md)\:\:setCursorAlternative
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Enables or disables the alternative cursor. The alternative cursor starts at the original cursor's position.

&nbsp;

## Synopses
#### 1)
```cpp
void setCursorAlternative(bool value) noexcept;
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