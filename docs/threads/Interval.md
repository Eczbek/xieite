# [xieite](../xieite.md)\:\:[threads](../threads.md)\:\:Interval
Defined in header [<xieite/threads/Interval.hpp>](../../include/xieite/threads/Interval.hpp)

&nbsp;

## Description
Runs a callback every set amount of time. Compile with `-pthread`

&nbsp;

## Synopsis
```cpp
struct Interval {
    template<std::invocable<> Invocable, xieite::concepts::ChronoDuration ChronoDuration>
    Interval(const Invocable&, ChronoDuration) noexcept;

    bool good() const;

    void stop();
};
```
#### Public members
## Contents
|- <a href="./Interval/constructor.md">Interval</a>
|- <a href="./Interval/good.md">good</a>
`- <a href="./Interval/stop.md">stop</a>

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
