# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Loop \{\}
Defined in header [<xieite/threads/loop.hpp>](../../../include/xieite/threads/loop.hpp)

&nbsp;

## Description
Runs a callback constantly.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Loop {
    Loop(const xieite::functors::Function<void()>&) noexcept;

    explicit operator bool() const noexcept;

    void stop() noexcept;
};
```
- [Loop\(\)](./structures/loop/1/operators/constructor.md)
- [operator typename\(\)](./structures/loop/1/operators/cast.md)
- [stop\(\)](./structures/loop/1/stop.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <print>
#include <thread>
#include "xieite/threads/loop.hpp"

int main() {
    auto loop = xieite::threads::Loop([] {
        static int i = 0;

        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::println("{}", ++i);
    });

    std::this_thread::sleep_for(std::chrono::seconds(5));
}
```
Possible output:
```
1
2
3
4
```
