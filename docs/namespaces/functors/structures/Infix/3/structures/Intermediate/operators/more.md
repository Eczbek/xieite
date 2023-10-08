# [xieite](../../../../../../../../xieite.md)\:\:[functors](../../../../../../../../functors.md)\:\:[Infix\<Functor\>](../../../../../../Infix.md)\:\:[Intermediate](../../../Intermediate.md)\:\:operator\>
Defined in header [<xieite/functors/Infix.hpp>](../../../../../../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename RightArgument>
requires(std::invocable<Functor, LeftArgument, RightArgument&&>)
friend constexpr std::invoke_result_t<Functor, LeftArgument, RightArgument&&> operator>(const xieite::functors::Infix<Functor>::Intermediate<LeftArgument>& infixIntermediate, RightArgument&& rightArgument);
```
