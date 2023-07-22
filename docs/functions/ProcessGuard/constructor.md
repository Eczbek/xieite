# [xieite](../../xieite.md)::[functions](../../functions.md)::[ProcessGuard](../ProcessGuard.md)::ProcessGuard
Defined in header [<xieite/functions/ProcessGuard.hpp>](../../../include/xieite/functions/ProcessGuard.hpp)

<br/>

Constructs a `xieite::functions::ProcessGuard`

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
