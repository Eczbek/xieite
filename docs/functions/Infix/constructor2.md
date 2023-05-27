# [xieite](../../../README.md)::[functions](../../functions.md)::[Infix<Result(LeftParameter, RightParameter)>](../Infix.md)::Infix
Defined in header [<xieite/functions/Infix.hpp>](../../../include/xieite/functions/Infix.hpp)

<br/>

Constructs a `xieite::functions::Infix` thing

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Infix(const xieite::concepts::Functional<Result(LeftParameter, RightParameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `xieite::concepts::Functional` which accepts a `LeftParameter` and a `RightParameter`, and returns a `Result`
