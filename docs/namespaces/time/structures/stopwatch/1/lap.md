# [xieite](../../../../../xieite.md)\:\:[time](../../../../../time.md)\:\:[Stopwatch<Clock>](../../../stopwatch.md)\:\:lap\<\>\(\)
Defined in header [<xieite/time/stopwatch.hpp>](../../../../../../include/xieite/time/stopwatch.hpp)

&nbsp;

## Description
Returns the current elapsed lap time.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Duration Duration = std::chrono::nanoseconds>
Duration lap() const noexcept;
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

    std::println("{}", stopwatch.template lap<std::chrono::seconds>().count());

    stopwatch.stop();

    std::println("{}", stopwatch.template lap<std::chrono::seconds>().count());
}
```
Possible output:
```
3
0
```
