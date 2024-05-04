# [xieite](../../../../../../../../../xieite.md)\:\:[functors](../../../../../../../../../functors.md)\:\:[Infix<Return_(LeftArgument_, RightArgument_)>](../../../../../../../infix.md)\:\:[Intermediate<LeftArgumentReference_>](../../../../intermediate.md)\:\:operator\>\<\>\(\)
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
Calls the underlying functor with both arguments.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename RightArgument_>
requires(std::invocable<Functor_, LeftArgument_, RightArgument_&&>)
friend constexpr std::invoke_result_t<Functor_, LeftArgument_, RightArgument_&&> operator>(const xieite::functors::Infix<Return_(LeftArgument_, RightArgument_)>::Intermediate<LeftArgument_>& infixIntermediate, RightArgument_&& rightArgument)
noexcept(xieite::concepts::NoThrowInvocable<Functor_, LeftArgument_, RightArgument_&&>);
```

&nbsp;

## [Example](../../../../operators/less.md)
