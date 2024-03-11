# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Timeout
Defined in header [<xieite/threads/timeout.hpp>](../../../include/xieite/threads/timeout.hpp)

&nbsp;

## Description
Runs a callback once after a set amount of time. Compile with `-pthread`.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Timeout {
    template<std::invocable<> Functor, xieite::concepts::Duration Duration>
    Timeout(const Functor&, Duration) noexcept;

    operator bool() const;

    void stop();
};
```
- [Timeout](./structures/timeout/1/operators/constructor.md)
- [operator typename](./structures/timeout/1/operators/cast.md)
- [stop](./structures/timeout/1/stop.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include "xieite/threads/timeout.hpp"

int main() {
    xieite::threads::Timeout timeout([] {
        std::cout << "Hello, world!\n";
    }, std::chrono::seconds(3));

    std::this_thread::sleep_for(std::chrono::seconds(1));

    timeout.stop();
}
```
Output:
```
```
