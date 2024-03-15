# [xieite](../../../../../../../../../xieite.md)\:\:[functors](../../../../../../../../../functors.md)\:\:[Infix<Result(LeftArgument, RightArgument)>](../../../../../../../infix.md)\:\:[Intermediate<LeftArgumentReference>](../../../../intermediate.md)\:\:operator>\(\)
Defined in header [<xieite/functors/infix.hpp>](../../../../../../../../../../include/xieite/functors/infix.hpp)

&nbsp;

## Description
Calls the underlying functor with both arguments.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename RightArgument>
requires(std::invocable<Functor, LeftArgument, RightArgument&&>)
friend constexpr std::invoke_result_t<Functor, LeftArgument, RightArgument&&> operator>(const xieite::functors::Infix<Result(LeftArgument, RightArgument)>::Intermediate<LeftArgument>& infixIntermediate, RightArgument&& rightArgument)
noexcept(xieite::concepts::NoThrowInvocable<Functor, LeftArgument, RightArgument&&>);
```

&nbsp;

## [Example](../../../../operators/less.md)
