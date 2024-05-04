# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[Infix<Return_(LeftArgument_, RightArgument_)>](../../../infix.md)\:\:Intermediate\<\> \{\}
Defined in header [<xieite/functors/infix.hpp>](../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
An intermediate state for an infix thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename LeftArgumentReference_>
struct Intermediate {
    constexpr Intermediate(const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>&, LeftArgumentReference_&&) noexcept;

    constexpr auto operator=(const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgument_>&) noexcept = delete;

    template<std::convertible_to<RightArgument_> RightArgumentReference_>
    friend constexpr Return_ operator>(xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgumentReference_>&&, RightArgumentReference_&&);
};
```
- [Intermediate\(\)](./structures/intermediate/1/operators/constructor.md)
- [operator>\(\)](./structures/intermediate/1/operators/more.md)

&nbsp;

## [Example](./operators/less.md#Example)
