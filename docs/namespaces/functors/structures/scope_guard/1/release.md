# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[ScopeGuard<Functor>](../../../scope_guard.md)\:\:release
Defined in header [<xieite/functors/scope_guard.hpp>](../../../../../../include/xieite/functors/scope_guard.hpp)

&nbsp;

## Description
Releases the guard, so that when it goes out of scope, the callback will not execute.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr void release() noexcept;
```
