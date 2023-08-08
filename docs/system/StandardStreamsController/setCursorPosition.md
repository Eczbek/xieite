# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:setCursorPosition
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Sets the terminal cursor's position

&nbsp;

## Synopsis
```cpp
void setCursorPosition(xieite::system::BufferPosition position) noexcept;
```
#### Function parameters
- `position` - A `xieite::system::BufferPosition`, the new cursor coordinates

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/system/terminal.hpp>

int main() {
    xieite::system::terminal.setCursorPosition({ 2, 5 });
    std::cout << "Hello, world!\n";
}
```
Possible output:
```


     Hello, world!
```
