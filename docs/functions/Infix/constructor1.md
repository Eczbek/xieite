# [xieite](../../../README.md)::[functions](../../functions.md)::[Infix<Result(Parameter)>](../Infix.md)::Infix
Defined in header [<xieite/functions/Infix.hpp>](../../../include/xieite/functions/Infix.hpp)

<br/>

Constructs a `xieite::functions::Infix` thing

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Infix(const xieite::concepts::Functional<Result(Parameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `xieite::concepts::Functional` which accepts a `Parameter` and returns a `Result`
