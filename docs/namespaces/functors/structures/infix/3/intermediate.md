# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[Infix<Result(LeftArgument, RightArgument)>](../../../infix.md)\:\:Intermediate
Defined in header [<xieite/functors/infix.hpp>](../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
An intermediate state for an infix thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename LeftArgumentReference>
struct Intermediate {
    constexpr Intermediate(const xieite::functors::Infix<Result(LeftArgument, RightArgument)>&, LeftArgumentReference&&) noexcept;

    constexpr auto operator=(const xieite::functors::Infix<Result(LeftArgument, RightArgument)>::Intermediate<LeftArgument>&) noexcept = delete;

    template<std::convertible_to<RightArgument> RightArgumentReference>
    friend constexpr Result operator>(xieite::functors::Infix<Result(LeftArgument, RightArgument)>::Intermediate<LeftArgumentReference>&&, RightArgumentReference&&);
};
```
##### Member functions
- [Intermediate](./structures/intermediate/1/operators/constructor.md)
- [operator>](./structures/intermediate/1/operators/more.md)

&nbsp;

## [Example](./operators/less.md)
