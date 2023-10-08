# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix\<Functor\>](../../../../Infix.md)\:\:operator\<
Defined in header [<xieite/functors/Infix.hpp>](../../../../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename LeftArgument>
requires(std::invocable<Functor, LeftArgument&&, xieite::types::Placeholder>)
[[nodiscard]] friend constexpr xieite::functors::Infix<Functor>::Intermediate<LeftArgument&&> operator<(LeftArgument&& leftArgument, const xieite::functors::Infix<Functor>& infix) noexcept;
```
