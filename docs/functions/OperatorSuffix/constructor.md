# [xieite](../../../README.md)::[functions](../../functions.md)::[OperatorSuffix<Result(LeftParameter)>](../OperatorSuffix.md)::OperatorSuffix
Defined in header [<xieite/functions/OperatorSuffix.hpp>](../../../include/xieite/functions/OperatorSuffix.hpp)

<br/>

Creates a `xieite::functions::OperatorSuffix` operator

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr OperatorSuffix(const xieite::concepts::Functional<Result(LeftParameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `xieite::concepts::Functional` of `Result` of `LeftParameter`
