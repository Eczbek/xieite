# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setInputCanon\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables canonical mode. When it is disabled, the input is read by bytes instead of by lines, therefore anything typed is read immediately instead of waiting for a newline.

&nbsp;

## Synopsis
#### 1)
```cpp
void setInputCanon(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdio>
#include <print>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setInputCanon(false);

    std::println("{}", std::fgetc(stdin));
}
```
Possible output:
```
h
```
