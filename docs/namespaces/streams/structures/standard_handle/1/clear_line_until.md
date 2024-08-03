# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:clearLineUntil\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Clears from the beginning of a line until the cursor.

&nbsp;

## Synopsis
#### 1)
```cpp
void clearLineUntil() noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    std::print("Hello,\nworld!");

    terminal.clearLineUntil();
}
```
Possible output:
```
Hello,
      
```
