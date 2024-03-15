# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setCursorPosition
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Sets the terminal cursor's position.

&nbsp;

## Synopsis
#### 1)
```cpp
void setCursorPosition(xieite::streams::Position position) const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(std::cin, std::cout);

    terminal.setCursorPosition({ 2, 5 });
    std::println("Hello, world!");
}
```
Possible output:
```


     Hello, world!
```
