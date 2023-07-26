# [xieite](../../xieite.md)::[functors](../../functors.md)::[ProcessGuard](../ProcessGuard.md)::ProcessGuard
Defined in header [<xieite/functors/ProcessGuard.hpp>](../../../include/xieite/functors/ProcessGuard.hpp)

<br/>

Constructs a `xieite::functors::ProcessGuard`

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::invocable<> Invocable>
constexpr ProcessGuard(const Invocable& invocable) noexcept;
```
### Template parameters
- `Invocable` - A type satisfying `std::invocable`
### Parameters
- `invocable` - An `Invocable` constant references
