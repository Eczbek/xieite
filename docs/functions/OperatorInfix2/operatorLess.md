# [xieite](../../../README.md)::[functions](../../functions.md)::[OperatorInfix<Result(LeftParameter, RightParameter), callback>](../OperatorInfix.md)::operator<

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
friend constexpr xieite::functions::OperatorInfix<Result(LeftParameter, RightParameter), callback>::Intermediate operator<(const LeftParameter& leftArgument, const xieite::functions::OperatorInfix<Result(LeftParameter, RightParameter), callback>&) noexcept;
```
### Parameters
- `leftArgument` - A `LeftParameter` constant reference
- An unnamed constant reference to this `xieite::functions::OperatorInfix`
### Return value
- An intermediate value until its `operator>` is called
