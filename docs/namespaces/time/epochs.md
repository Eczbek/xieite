# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Epochs
Defined in header [<xieite/time/epochs.hpp>](../../../include/xieite/time/epochs.hpp)

&nbsp;

## Description
An alias to a `std::chrono::duration` specialization to represent epochs.

&nbsp;

## Synopsis
#### 1)
```cpp
using Epochs = std::chrono::duration<std::intmax_t, std::ratio<31556952000000>>;
```

&nbsp;

## Example
```cpp
#include <print>
#include <thread>
#include "xieite/time/epochs.hpp"

int main() {
    std::this_thread::sleep_for(xieite::time::Epochs(4));

    std::println("Hello, world!");
}
```
Output (in 4'000'000 years):
```
Hello, world!
```
