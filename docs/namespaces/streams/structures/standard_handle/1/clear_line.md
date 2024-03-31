# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearLine\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Clears a line.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearLine() noexcept;
```
#### 2)
```cpp
void clearLine(xieite::streams::Position position) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello,");

    terminal.clearLine();

    std::println("world!");
}
```
Possible output:
```
      world!
```
