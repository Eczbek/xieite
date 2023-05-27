# [xieite](../../../README.md)::[functions](../../functions.md)::[Prefix<Result(RightParameter)>](../Prefix.md)::Prefix
Defined in header [<xieite/functions/Prefix.hpp>](../../../include/xieite/functions/Prefix.hpp)

<br/>

Creates a `xieite::functions::Prefix` operator

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Prefix(const xieite::concepts::Functional<Result(RightParameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `xieite::concepts::Functional` of `Result` of `RightParameter`
