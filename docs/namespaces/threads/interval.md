# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Interval
Defined in header [<xieite/threads/interval.hpp>](../../../include/xieite/threads/interval.hpp)

&nbsp;

## Description
Runs a callback every set amount of time. Compile with `-pthread`.

&nbsp;

## Synopses
#### 1)
```cpp
struct Interval {
    template<std::invocable<> Functor, xieite::concepts::TemporalDuration TemporalDuration>
    Interval(const Functor&, TemporalDuration) noexcept;

    operator bool() const;

    void stop();
};
```
##### Member functions
- [Interval](./structures/interval/1/operators/constructor.md)
- [operator typename](./structures/interval/1/operators/cast.md)
- [stop](./structures/interval/1/stop.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/interval.hpp>

int main() {
    xieite::threads::Interval interval([] {
        static int i = 0;

        std::cout << ++i << '\n';
    }, std::chrono::seconds(1));

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
