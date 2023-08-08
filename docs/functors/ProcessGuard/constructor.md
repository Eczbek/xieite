# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:[ProcessGuard](../ProcessGuard.md)\:\:ProcessGuard
Defined in header [<xieite/functors/ProcessGuard.hpp>](../../../include/xieite/functors/ProcessGuard.hpp)

&nbsp;

## Description
Constructs a `xieite::functors::ProcessGuard`

&nbsp;

## Synopsis
```cpp
template<std::invocable<> Invocable>
constexpr ProcessGuard(const Invocable& invocable) noexcept;
```
#### Template parameters
- `Invocable` - A type satisfying `std::invocable`
#### Function parameters
- `invocable` - An `Invocable` constant references
