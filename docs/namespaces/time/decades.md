# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Decades
Defined in header [<xieite/time/decades.hpp>](../../../include/xieite/time/decades.hpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent decades.

&nbsp;

## Synopsis
#### 1)
```cpp
using Decades = std::chrono::duration<std::intmax_t, std::ratio<315569520>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <thread>
#include "xieite/time/decades.hpp"

int main() {
    std::this_thread::sleep_for(xieite::time::Decades(5));

    std::println("Hello, world!");
}
```
Output (in 50 years):
```
Hello, world!
```
