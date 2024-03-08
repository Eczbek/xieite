# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[ProcessGuard](../../../../process_guard.md)\:\:ProcessGuard
Defined in header [<xieite/functors/process_guard.hpp>](../../../../../../../include/xieite/functors/process_guard.hpp)

&nbsp;

## Description
Constructs a `xieite::functors::ProcessGuard`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Functable<void()> Functor, auto = [] {}>
ProcessGuard(Functor&& callback) noexcept;
```

&nbsp;

## [Example](../../../../process_guard.md#Example)
