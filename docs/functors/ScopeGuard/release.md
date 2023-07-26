# [xieite](../../xieite.md)::[functors](../../functors.md)::[ScopeGuard<Invocable>](../ScopeGuard.md)::release
Defined in header [<xieite/functors/ScopeGuard.hpp>](../../../include/xieite/functors/ScopeGuard.hpp)

<br/>

Releases the guard, so that when it goes out of scope, the callback will not execute

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr void release() noexcept;
```
