# [xieite](../../../../../../../../xieite.md)\:\:[functors](../../../../../../../../functors.md)\:\:[Infix\<callback\>](../../../../../../Infix.md)\:\:[Intermediate](../../../Intermediate.md)\:\:operator\>
Defined in header [<xieite/functors/Infix.hpp>](../../../../../../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename RightArgument>
requires(std::invocable<decltype(callback), LeftArgument, const RightArgument&>)
friend constexpr std::invoke_result_t<decltype(callback), LeftArgument, const RightArgument&> operator>(xieite::functors::Infix<callback>::Intermediate<LeftArgument>& infixIntermediate, const RightArgument& rightArgument);
```
#### 2)
```cpp
template<typename RightArgument>
requires(std::invocable<decltype(callback), LeftArgument, RightArgument&>)
friend constexpr std::invoke_result_t<decltype(callback), LeftArgument, RightArgument&> operator>(xieite::functors::Infix<callback>::Intermediate<LeftArgument>& infixIntermediate, RightArgument& rightArgument);
```
