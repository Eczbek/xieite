# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Timeout \{\}
Defined in header [<xieite/threads/timeout.hpp>](../../../include/xieite/threads/timeout.hpp)

&nbsp;

## Description
Runs a callback once after a set amount of time.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Timeout {
    template<xieite::concepts::Duration Duration>
    Timeout(const xieite::functors::Function<void()>&, Duration) noexcept;

    explicit operator bool() const noexcept;

    void stop() noexcept;
};
```
- [Timeout\(\)](./structures/timeout/1/operators/constructor.md)
- [operator typename\(\)](./structures/timeout/1/operators/cast.md)
- [stop\(\)](./structures/timeout/1/stop.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <print>
#include <thread>
#include "xieite/threads/timeout.hpp"

int main() {
    auto timeout = xieite::threads::Timeout([] {
        std::println("Hello,");
    }, std::chrono::seconds(3));

    std::println("world!");
}
```
Output:
```
world!
Hello,
```
