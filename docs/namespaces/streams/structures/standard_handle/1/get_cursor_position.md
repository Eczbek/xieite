# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:getCursorPosition\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Gets the cursor's position in the terminal.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] xieite::streams::Position getCursorPosition() noexcept;
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

    terminal.setCursorPosition(xieite::streams::Position(0, 0));
    std::print("12345");

    auto position = terminal.getCursorPosition();
    std::println("\n({}, {})", position.row, position.column);
}
```
Possible output:
```
12345
(0, 5)
```
