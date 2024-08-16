# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[ScopeGuard](../../../../scope_guard.md)\:\:ScopeGuard\<\>\(\)
Defined in header [<xieite/functors/scope_guard.hpp>](../../../../../../../include/xieite/functors/scope_guard.hpp)

&nbsp;

## Description
Constructs a `xieite::functors::ScopeGuard`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::invocable<> Functor>
constexpr ScopeGuard(Functor&& callback) noexcept;
```

&nbsp;

## [Example](../../../../scope_guard.md#Example)
