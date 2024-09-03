# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Interval](../../../interval.md)\:\:stop\(\)
Defined in fragment [xieite:threads.Interval](../../../../../../src/threads/interval.cpp)

&nbsp;

## Description
Stops a `xieite::threads::Interval`, and further callback calls. Immediately returns execution to the caller thread, without waiting for the loop to complete.

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
    auto interval = xieite::threads::Interval([] {
        std::println("xyz");
    }, std::chrono::seconds(3));

    interval.stop();
}
```
Possible output:
```
```
