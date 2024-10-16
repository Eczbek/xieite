# [xieite](../../xieite.md)\:\:[time](../../time.md)\:\:Stopwatch\<\> \{\}
Defined in fragment [xieite:time.Stopwatch](../../../src/time/stopwatch.cpp)

&nbsp;

## Description
A stopwatch structure.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Clock Clock>
struct Stopwatch {
    void start() noexcept;

    void stop() noexcept;

    void reset() noexcept;

    template<xieite::concepts::Duration Duration = std::chrono::nanoseconds>
    Duration lap() const noexcept;

    template<xieite::concepts::Duration Duration = std::chrono::nanoseconds>
    Duration total() const noexcept;
};
```
- [start\(\)](./structures/stopwatch/1/start.md)
- [stop\(\)](./structures/stopwatch/1/stop.md)
- [reset\(\)](./structures/stopwatch/1/reset.md)
- [lap\<\>\(\)](./structures/stopwatch/1/lap.md)
- [total\<\>\(\)](./structures/stopwatch/1/total.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::time::Stopwatch<std::high_resolution_clock> stopwatch;

    stopwatch.start();
    for (int i = 0; i < 10'000; ++i) {
        std::print("");
    }
    stopwatch.stop();

    std::println("{} nanoseconds", stopwatch.template total<std::chrono::nanoseconds>().count());
}
```
Possible output:
```
3890975 nanoseconds
```
