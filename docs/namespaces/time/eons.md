# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Eons
Defined in header [<xieite/time/eons.hpp>](../../../include/xieite/time/eons.hpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent eons.

&nbsp;

## Synopsis
#### 1)
```cpp
using Eons = std::chrono::duration<std::intmax_t, std::ratio<31556952000000000>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <thread>
#include "xieite/time/eons.hpp"

int main() {
    std::this_thread::sleep_for(xieite::time::Eons(7));

    std::println("Hello, world!");
}
```
Output (in 7'000'000'000 years):
```
Hello, world!
```
