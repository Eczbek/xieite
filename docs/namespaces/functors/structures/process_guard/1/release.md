# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[ProcessGuard](../../../process_guard.md)\:\:release\(\)
Defined in fragment [xieite:functors.ProcessGuard](../../../../../../src/functors/process_guard.cpp)

&nbsp;

## Description
Releases the guard, so that when the process ends, the callback will not execute.

&nbsp;

## Synopsis
#### 1)
```cpp
void release() noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    xieite::functors::ProcessGuard guard = [] {
        std::println("Hello, world!");
    };

    guard.release();
}
```
Output:
```
```
