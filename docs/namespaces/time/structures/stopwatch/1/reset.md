# [xieite](../../../../../xieite.md)\:\:[time](../../../../../time.md)\:\:[Stopwatch<Clock>](../../../stopwatch.md)\:\:reset\(\)
Defined in fragment [xieite:time.Stopwatch](../../../../../../src/time/stopwatch.cpp)

&nbsp;

## Description
Resets the total and lap times of a `xieite::time::Stopwatch<Clock>`.

&nbsp;

## Synopsis
#### 1)
```cpp
void reset() noexcept;
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

    stopwatch.reset();

    std::println("{} seconds", stopwatch.template total<std::chrono::seconds>().count());
}
```
Possible output:
```
0
```
