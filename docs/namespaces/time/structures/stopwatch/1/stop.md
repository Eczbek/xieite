# [xieite](../../../../../xieite.md)\:\:[time](../../../../../time.md)\:\:[Stopwatch<Clock>](../../../stopwatch.md)\:\:stop\(\)
Defined in fragment [xieite:time.Stopwatch](../../../../../../src/time/stopwatch.cpp)

&nbsp;

## Description
Stops a `xieite::time::Stopwatch<Clock>` and resets the current lap.

&nbsp;

## Synopsis
#### 1)
```cpp
void stop() noexcept;
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

    stopwatch.stop();

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::println("{} seconds", stopwatch.template total<std::chrono::seconds>().count());
}
```
Possible output:
```
3
```
