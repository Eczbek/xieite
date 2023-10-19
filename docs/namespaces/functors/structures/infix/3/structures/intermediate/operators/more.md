# [xieite](../../../../../../../../xieite.md)\:\:[functors](../../../../../../../../functors.md)\:\:[Infix<Functor>](../../../../../../infix.md)\:\:[Intermediate<LeftArgument>](../../../intermediate.md)\:\:operator>
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename RightArgument>
requires(std::invocable<Functor, LeftArgument, RightArgument&&>)
friend constexpr std::invoke_result_t<Functor, LeftArgument, RightArgument&&> operator>(const xieite::functors::Infix<Functor>::Intermediate<LeftArgument>& infixIntermediate, RightArgument&& rightArgument);
```
