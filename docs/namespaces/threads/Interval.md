# [xieite](../../xieite.md)\:\:[threads](../../threads.md)\:\:Interval
Defined in header [<xieite/threads/Interval.hpp>](../../../include/xieite/threads/Interval.hpp)

&nbsp;

## Description
Runs a callback every set amount of time. Compile with `-pthread`.

&nbsp;

## Synopses
#### 1)
```cpp
struct Interval {
    template<std::invocable<> Functor, xieite::concepts::ChronoDuration ChronoDuration>
    Interval(const Functor&, ChronoDuration) noexcept;

    bool good() const;

    void stop();
};
```
##### Member functions
- [Interval](./structures/Interval/1/operators/constructor.md)
- [good](./structures/Interval/1/good.md)
- [stop](./structures/Interval/1/stop.md)

&nbsp;

## Example
```cpp
#include <chrono>
#include <iostream>
#include <thread>
#include <xieite/threads/Interval.hpp>

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