# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:ScopeGuard \{\}
Defined in header [<xieite/functors/scope_guard.hpp>](../../../include/xieite/functors/scope_guard.hpp)

&nbsp;

## Description
Executes a callback when it goes out of scope.

&nbsp;

## Synopsis
#### 1)
```cpp
struct ScopeGuard {
    constexpr ScopeGuard(const xieite::functors::Function<void()>&) noexcept;

    constexpr void release() noexcept;
};
```
- [ScopeGuard\(\)](./structures/scope_guard/1/operators/constructor.md)
- [release\(\)](./structures/scope_guard/1/release.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/functors/scope_guard.hpp"

int main() {
    xieite::functors::ScopeGuard _ = [] {
        std::println("foo");
    };

    std::println("bar");
}
```
Output:
```
bar
foo
```
