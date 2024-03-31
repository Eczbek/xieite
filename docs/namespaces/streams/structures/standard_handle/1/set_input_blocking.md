# [xieite](../../../../../xieite.md)\:\:[streams](../../../../../streams.md)\:\:[StandardHandle](../../../standard_handle.md)\:\:setInputBlocking\(\)
Defined in header [<xieite/streams/standard_handle.hpp>](../../../../../../include/xieite/streams/standard_handle.hpp)

&nbsp;

## Description
Enables or disables blocking mode. When disabled, any input reading will access the existing input buffer without waiting for new input.

&nbsp;

## Synopsis
#### 1)
```cpp
void setInputBlocking(bool value) noexcept;
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

    terminal.setInputBlocking(false);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::println("{}", terminal.readCharacter());
}
```
Possible output:
```
h
```
