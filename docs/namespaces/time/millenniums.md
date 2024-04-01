# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Millenniums
Defined in header [<xieite/time/millenniums.hpp>](../../../include/xieite/time/millenniums.hpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent millenniums.

&nbsp;

## Synopsis
#### 1)
```cpp
using Millenniums = std::chrono::duration<std::intmax_t, std::ratio<31556952000>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <thread>
#include "xieite/time/millenniums.hpp"

int main() {
    std::this_thread::sleep_for(xieite::time::Millenniums(2));

    std::println("Hello, world!");
}
```
Output (in 2000 years):
```
Hello, world!
```
