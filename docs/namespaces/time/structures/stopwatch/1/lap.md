# [xieite](../../../../../xieite.md)\:\:[time](../../../../../time.md)\:\:[Stopwatch<Clock>](../../../stopwatch.md)\:\:lap\<\>\(\)
Defined in fragment [xieite:time.Stopwatch](../../../../../../src/time/stopwatch.cpp)

&nbsp;

## Description
Returns the current elapsed lap time.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Duration Duration = std::chrono::nanoseconds>
Duration lap() const noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::time::Stopwatch<std::chrono::high_resolution_clock> stopwatch;

    stopwatch.start();
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::println("{}", stopwatch.template lap<std::chrono::seconds>().count());

    stopwatch.stop();

    std::println("{}", stopwatch.template lap<std::chrono::seconds>().count());
}
```
Possible output:
```
3
0
```
