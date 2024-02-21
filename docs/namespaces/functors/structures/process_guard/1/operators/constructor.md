# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[ProcessGuard](../../../../process_guard.md)\:\:ProcessGuard
Defined in header [<xieite/functors/process_guard.hpp"](../../../../../../../include/xieite/functors/process_guard.hpp)

&nbsp;

## Description
Constructs a `xieite::functors::ProcessGuard`.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::invocable<> Functor>
constexpr ProcessGuard(const Functor callback) noexcept;
```
