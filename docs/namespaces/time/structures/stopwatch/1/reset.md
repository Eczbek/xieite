# [xieite](../../../../../xieite.md)\:\:[time](../../../../../time.md)\:\:[Stopwatch<Clock>](../../../stopwatch.md)\:\:reset\(\)
Defined in header [<xieite/time/stopwatch.hpp>](../../../../../../include/xieite/time/stopwatch.hpp)

&nbsp;

## Description
Resets the total and lap times of a `xieite::time::Stopwatch<Clock>`.

&nbsp;

## Synopsis
#### 1)
```cpp
void reset() noexcept;
```

&nbsp;

## Example
```cpp
#include <chrono>
#include <print>
#include <thread>
#include "xieite/time/stopwatch.hpp"

int main() {
    xieite::time::Stopwatch<std::chrono::high_resolution_clock> stopwatch;

    stopwatch.start();

    std::this_thread::sleep_for(std::chrono::seconds(3));

    stopwatch.reset();

    std::println("{} seconds", stopwatch.template total<std::chrono::seconds>().count());
}
```
Possible output:
```
0
```
