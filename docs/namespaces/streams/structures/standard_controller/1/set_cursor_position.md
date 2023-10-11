# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorPosition
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

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
#include <xieite/streams/standard_handle.hpp>

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    terminal.setCursorPosition({ 2, 5 });
    std::cout << "Hello, world!\n";
}
```
Possible output:
```


     Hello, world!
```
