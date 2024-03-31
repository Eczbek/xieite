# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Interval](../../../../interval.md)\:\:operator typename\(\)
Defined in header [<xieite/threads/interval.hpp>](../../../../../../../include/xieite/threads/interval.hpp)

&nbsp;

## Description
The boolean cast returns `true` if the interval is still running, and `false` if it has been stopped.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] explicit operator bool() const noexcept;
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

    std::println("{}", static_cast<bool>(interval));
}
```
Output:
```
false
```
