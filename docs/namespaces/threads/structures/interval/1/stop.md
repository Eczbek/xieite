# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Interval](../../../interval.md)\:\:stop\(\)
Defined in header [<xieite/threads/interval.hpp>](../../../../../../include/xieite/threads/interval.hpp)

&nbsp;

## Description
Stops a `xieite::threads::Interval`, and further callback calls. Immediately returns execution to the caller thread, without waiting for the loop to complete.

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
#include "xieite/threads/interval.hpp"

int main() {
    auto interval = xieite::threads::Interval([] {
        std::println("xyz");
    }, std::chrono::seconds(3));

    interval.stop();
}
```
Possible output:
```
```
