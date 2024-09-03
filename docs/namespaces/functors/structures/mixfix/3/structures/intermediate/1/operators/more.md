# [xieite](../../../../../../../../../xieite.md)\:\:[functors](../../../../../../../../../functors.md)\:\:[Mixfix<Return(LeftArgument, RightArgument)>](../../../../../../../mixfix.md)\:\:[Intermediate<LeftArgumentReference>](../../../../intermediate.md)\:\:operator\>\<\>\(\)
Defined in fragment [xieite:functors.Mixfix](../../../../../../../../../../src/functors/mixfix.cpp)

&nbsp;

## Description
Calls the underlying functor with both arguments.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename RightArgument>
requires(std::invocable<Functor, LeftArgument, RightArgument&&>)
friend constexpr std::invoke_result_t<Functor, LeftArgument, RightArgument&&> operator>(const xieite::functors::Mixfix<Return(LeftArgument, RightArgument)>::Intermediate<LeftArgument>& mixfixIntermediate, RightArgument&& rightArgument)
noexcept(std::is_nothrow_invocable_v<Functor, LeftArgument, RightArgument&&>);
```

&nbsp;

## [Example](../../../../operators/less.md)
