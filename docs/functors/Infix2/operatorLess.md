# [xieite](../../xieite.md)::[functors](../../functors.md)::[Infix<Result(LeftParameter, RightParameter), callback>](../Infix.md)::operator<

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
friend constexpr xieite::functors::Infix<Result(LeftParameter, RightParameter), callback>::Intermediate operator<(const LeftParameter& leftArgument, const xieite::functors::Infix<Result(LeftParameter, RightParameter), callback>&) noexcept;
```
### Parameters
- `leftArgument` - A `LeftParameter` constant reference
- An unnamed constant reference to this `xieite::functors::Infix`
### Return value
- An intermediate value until its `operator>` is called
