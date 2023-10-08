# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[Infix\<Functor\>](../../../Infix.md)\:\:Intermediate
Defined in header [<xieite/functors/Infix.hpp>](../../../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Description
An intermediate state for an infix.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename LeftArgument>
class Intermediate {
public:
    constexpr Intermediate(Functor&&, LeftArgument&&);

    constexpr auto operator=(const xieite::functions::Infix<Functor>::Intermediate<LeftArgument>&) = delete;

    template<typename RightArgument>
    requires(std::invocable<Functor, LeftArgument, RightArgument&&>)
    friend constexpr std::invoke_result_t<Functor, LeftArgument, RightArgument&&> operator>(const xieite::functors::Infix<Functor>::Intermediate<LeftArgument>&, RightArgument&&);
};
```
##### Member functions
- [Intermediate](./structures/Intermediate/operators/constructor.md)
- [operator>](./structures/Intermediate/operators/more.md)
