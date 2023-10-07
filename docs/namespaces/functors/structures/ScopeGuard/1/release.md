# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[ScopeGuard\<Invocable\>](../../../ScopeGuard.md)\:\:release
Defined in header [<xieite/functors/ScopeGuard.hpp>](../../../../../../include/xieite/functors/ScopeGuard.hpp)

&nbsp;

## Description
Releases the guard, so that when it goes out of scope, the callback will not execute.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr void release() noexcept;
```
