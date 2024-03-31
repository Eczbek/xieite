# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearScreenUntil\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Clears from the beginning of the screen until the cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearScreenUntil() noexcept;
```
#### 2)
```cpp
void clearScreenUntil(xieite::streams::Position position) noexcept;
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

    terminal.clearScreenUntil();

    std::print("world!");
}
```
Possible output:
```
      world!
```
