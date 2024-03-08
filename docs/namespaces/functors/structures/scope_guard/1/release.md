# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[ScopeGuard](../../../scope_guard.md)\:\:release
Defined in header [<xieite/functors/scope_guard.hpp>](../../../../../../include/xieite/functors/scope_guard.hpp)

&nbsp;

## Description
Releases the guard, so that when it goes out of scope, the callback will not execute.

&nbsp;

## Synopsis
#### 1)
```cpp
constexpr void release() noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/scope_guard.hpp"

int main() {
    xieite::functors::ScopeGuard guard = [] {
        std::println("Hello, world!");
    };

    guard.release();
}
```
Output:
```
```
