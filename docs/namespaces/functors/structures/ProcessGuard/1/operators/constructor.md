# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[ProcessGuard](../../../../ProcessGuard.md)\:\:ProcessGuard
Defined in header [<xieite/functors/ProcessGuard.hpp>](../../../../../../../include/xieite/functors/ProcessGuard.hpp)

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
