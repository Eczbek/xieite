# [xieite](../../../../../xieite.md)\:\:[threads](../../../../../threads.md)\:\:[Timeout](../../../timeout.md)\:\:stop\(\)
Defined in fragment [xieite:threads.Timeout](../../../../../../src/threads/timeout.cpp)

&nbsp;

## Description
Stops a `xieite::threads::Timeout` and its callback call. Returns execution to the caller thread, without waiting for the timout to complete.

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
    auto timeout1 = xieite::threads::Timeout([] {
        std::println("abc");
    }, std::chrono::seconds(3));

    auto timeout2 = xieite::threads::Timeout([] {
        std::println("xyz");
    }, std::chrono::seconds(3));

    timeout1.stop();
}
```
Output:
```
xyz
```
