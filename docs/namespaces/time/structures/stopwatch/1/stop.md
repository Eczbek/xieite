# [xieite](../../../../../xieite.md)\:\:[time](../../../../../time.md)\:\:[Stopwatch<Clock_>](../../../stopwatch.md)\:\:stop\(\)
Defined in header [<xieite/time/stopwatch.hpp>](../../../../../../include/xieite/time/stopwatch.hpp)

&nbsp;

## Description
Stops a `xieite::time::Stopwatch<Clock_>` and resets the current lap.

&nbsp;

## Synopsis
#### 1)
```cpp
void stop() noexcept;
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

    stopwatch.stop();

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::println("{} seconds", stopwatch.template total<std::chrono::seconds>().count());
}
```
Possible output:
```
3
```
