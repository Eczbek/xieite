# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setInputEcho\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables echoing. When echoing is disabled, pressed keys will not be visibly reflected in the terminal.

&nbsp;

## Synopsis
#### 1)
```cpp
void setInputEcho(bool value) noexcept;
```

&nbsp;

## Example
```cpp
#include <chrono>
#include <cstdio>
#include <print>
#include <thread>
#include "xieite/streams/standard_handle.hpp"

int main() {
    auto terminal = xieite::streams::StandardHandle(stdin, stdout);

    terminal.setInputEcho(false);

    std::println("{}", terminal.readCharacter());
}
```
Possible output:
```
h
```
