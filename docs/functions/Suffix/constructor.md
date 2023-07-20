# [xieite](../../xieite.md)::[functions](../../functions.md)::[Suffix<Result(LeftParameter)>](../Suffix.md)::Suffix
Defined in header [<xieite/functions/Suffix.hpp>](../../../include/xieite/functions/Suffix.hpp)

<br/>

Creates a `xieite::functions::Suffix` operator

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Suffix(const xieite::concepts::Functable<Result(LeftParameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - A constant reference to a value of any type satisfying `xieite::concepts::Functable` of `Result` of `LeftParameter`
