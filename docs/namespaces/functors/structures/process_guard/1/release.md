# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[ProcessGuard](../../../process_guard.md)\:\:release\(\)
Defined in header [<xieite/functors/process_guard.hpp>](../../../../../../include/xieite/functors/process_guard.hpp)

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
#include <print>
#include "xieite/functors/process_guard.hpp"

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
