# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Centuries
Defined in header [<xieite/time/centuries.hpp>](../../../include/xieite/time/centuries.hpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent centuries.

&nbsp;

## Synopsis
#### 1)
```cpp
using Centuries = std::chrono::duration<std::intmax_t, std::ratio<3155695200>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <thread>
#include "xieite/time/centuries.hpp"

int main() {
    std::this_thread::sleep_for(xieite::time::Centuries(3));

    std::println("Hello, world!");
}
```
Output (in 300 years):
```
Hello, world!
```
