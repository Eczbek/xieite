# [xieite](../../xieite.md)::[functions](../../functions.md)::[Infix<Result(LeftParameter, RightParameter), callback>](../Infix.md)::operator<

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
friend constexpr xieite::functions::Infix<Result(LeftParameter, RightParameter), callback>::Intermediate operator<(const LeftParameter& leftArgument, const xieite::functions::Infix<Result(LeftParameter, RightParameter), callback>&) noexcept;
```
### Parameters
- `leftArgument` - A `LeftParameter` constant reference
- An unnamed constant reference to this `xieite::functions::Infix`
### Return value
- An intermediate value until its `operator>` is called
