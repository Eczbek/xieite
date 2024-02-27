# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:ScopeGuard
Defined in header [<xieite/functors/scope_guard.hpp>](../../../include/xieite/functors/scope_guard.hpp)

&nbsp;

## Description
Executes a callback when it goes out of scope.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::invocable<> Functor>
struct ScopeGuard {
    ScopeGuard(Functor&&);

    void release();
};
```
##### Member functions
- [ScopeGuard](./structures/scope_guard/1/operators/constructor.md)
- [release](./structures/scope_guard/1/release.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/functors/scope_guard.hpp"

int main() {
    xieite::functors::ScopeGuard guard([] {
        std::cout << "foo\n";
    });

    std::cout << "bar\n";
}
```
Output:
```
bar
foo
```
