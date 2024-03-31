# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:getScreenSize\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Gets the terminal screen size, in rows and columns.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] xieite::streams::Position getScreenSize() noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    auto size = terminal.getScreenSize();
    std::println("({}, {})", size.row, size.column);
}
```
Possible output:
```
(53, 197)
```
