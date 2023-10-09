# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardController](../../../standard_controller.md)\:\:setCursorPosition
Defined in header [<xieite/streams/standard_controller.hpp>](../../../../../../include/xieite/streams/standard_controller.hpp)

&nbsp;

## Description
Sets the terminal cursor's position.

&nbsp;

## Synopses
#### 1)
```cpp
void setCursorPosition(xieite::streams::Position position) const noexcept;
```

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
