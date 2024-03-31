# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearScreenFrom\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Clears from the cursor until the end of the screen.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearScreenFrom() noexcept;
```
#### 2)
```cpp
void clearScreenFrom(xieite::streams::Position position) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello,\nworld!\r");

    terminal.clearScreenFrom();
}
```
Possible output:
```
Hello,
      
```
