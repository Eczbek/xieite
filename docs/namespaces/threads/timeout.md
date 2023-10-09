# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Timeout
Defined in header [<xieite/threads/timeout.hpp>](../../../include/xieite/threads/timeout.hpp)

&nbsp;

## Description
Runs a callback once after a set amount of time. Compile with `-pthread`.

&nbsp;

## Synopses
#### 1)
```cpp
struct Timeout {
    template<std::invocable<> Functor, xieite::concepts::TemporalDuration TemporalDuration>
    Timeout(const Functor&, TemporalDuration) noexcept;

    bool good() const;

    void stop();
};
```
##### Member functions
- [Timeout](./structures/timeout/1/operators/constructor.md)
- [good](./structures/timeout/1/good.md)
- [stop](./structures/timeout/1/stop.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/timeout.hpp>

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
