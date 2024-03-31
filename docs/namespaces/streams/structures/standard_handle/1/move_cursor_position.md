# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:moveCursorPosition\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Moves the terminal cursor's position.

&nbsp;

## Synopsis
#### 1)
```cpp
void moveCursorPosition(xieite::streams::Position difference) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/position.hpp"
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.clearScreen();
    terminal.setCursorPosition(xieite::streams::Position(0, 0));
    terminal.moveCursorPosition(xieite::streams::Position(2, 3));

    std::println("Hello, world!");
}
```
Possible output:
```


  Hello, world!
```
