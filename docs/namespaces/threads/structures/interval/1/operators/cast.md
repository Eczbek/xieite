# [xieite](../../../../../../xieite.md)\:\:[threads](../../../../../../threads.md)\:\:[Interval](../../../../interval.md)\:\:operator typename\(\)
Defined in fragment [xieite:threads.Interval](../../../../../../../src/threads/interval.cpp)

&nbsp;

## Description
The boolean cast returns `true` if the interval is still running, and `false` if it has been stopped.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] explicit operator bool() const noexcept;
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

    std::println("{}", static_cast<bool>(interval));
}
```
Output:
```
false
```
