# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix<Functor>](../../../../infix.md)\:\:operator<
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename LeftArgument>
requires(std::invocable<Functor, LeftArgument&&, xieite::types::Placeholder>)
[[nodiscard]] friend constexpr xieite::functors::Infix<Functor>::Intermediate<LeftArgument&&> operator<(LeftArgument&& leftArgument, const xieite::functors::Infix<Functor>& infix) noexcept;
```
