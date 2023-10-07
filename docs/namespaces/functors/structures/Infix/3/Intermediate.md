# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[Infix\<callback\>](../../../Infix.md)\:\:Intermediate
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
    constexpr Intermediate(const LeftArgument&) noexcept;

    constexpr auto operator=(const xieite::functions::Infix<callback>::Intermediate<LeftArgument>&) = delete;

    template<typename RightArgument>
    requires(std::invocable<decltype(callback), LeftArgument, const RightArgument&>)
    friend constexpr std::invoke_result_t<decltype(callback), LeftArgument, const RightArgument&> operator>(xieite::functors::Infix<callback>::Intermediate<LeftArgument>&, const RightArgument&);

    template<typename RightArgument>
    requires(std::invocable<decltype(callback), LeftArgument, RightArgument&>)
    friend constexpr std::invoke_result_t<decltype(callback), LeftArgument, RightArgument&> operator>(xieite::functors::Infix<callback>::Intermediate<LeftArgument>&, RightArgument&);
};
```
##### Member functions
- [Intermediate](./structures/Intermediate/operators/constructor.md)
- [operator>](./structures/Intermediate/operators/more.md)
