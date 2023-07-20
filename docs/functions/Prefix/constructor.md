# [xieite](../../xieite.md)::[functions](../../functions.md)::[Prefix<Result(RightParameter)>](../Prefix.md)::Prefix
Defined in header [<xieite/functions/Prefix.hpp>](../../../include/xieite/functions/Prefix.hpp)

<br/>

Creates a `xieite::functions::Prefix` operator

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Prefix(const xieite::concepts::Functable<Result(RightParameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - A constant reference to a value of any type satisfying `xieite::concepts::Functable` of `Result` of `RightParameter`
