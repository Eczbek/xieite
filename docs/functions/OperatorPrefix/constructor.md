# [xieite](../../../README.md)::[functions](../../functions.md)::[OperatorPrefix<Result(RightParameter)>](../OperatorPrefix.md)::OperatorPrefix
Defined in header [<xieite/functions/OperatorPrefix.hpp>](../../../include/xieite/functions/OperatorPrefix.hpp)

<br/>

Creates a `xieite::functions::OperatorPrefix` operator

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr OperatorPrefix(const xieite::concepts::Functional<Result(RightParameter)> auto& callback) noexcept;
```
### Parameters
- `callback` - An `auto` constant reference, satisfying `xieite::concepts::Functional` of `Result` of `RightParameter`
