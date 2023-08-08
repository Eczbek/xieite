# [xieite](../../xieite.md)\:\:[system](../../system.md)\:\:[StandardStreamsController\<inputStream, outputStream\>](../StandardStreamsController.md)\:\:setScreenAlternative
Defined in header [<xieite/system/StandardStreamsController.hpp>](../../../include/xieite/system/StandardStreamsController.hpp)

&nbsp;

## Description
Enables or disables the alternative screen

&nbsp;

## Synopsis
```cpp
void setScreenAlternative(bool value) noexcept;
```
#### Function parameters
- `value` - A `bool` to determine whether to save or restore the screen

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
