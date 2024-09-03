# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[ScopeGuard](../../../scope_guard.md)\:\:release\(\)
Defined in fragment [xieite:functors.ScopeGuard](../../../../../../src/functors/scope_guard.cpp)

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
import std;
import xieite;

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
