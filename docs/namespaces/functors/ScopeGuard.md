# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:ScopeGuard
Defined in header [<xieite/functors/ScopeGuard.hpp>](../../../include/xieite/functors/ScopeGuard.hpp)

&nbsp;

## Description
Executes a callback when it goes out of scope.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::invocable<> Functor>
struct ScopeGuard {
    ScopeGuard(Functor&&);

    void release();
};
```
##### Member functions
- [ScopeGuard](./structures/ScopeGuard/1/operators/constructor.md)
- [release](./structures/ScopeGuard/1/release.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/functors/ScopeGuard.hpp>

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
