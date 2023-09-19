# [xieite](../../../../../../xieite.md)\:\:[functors](../../../../../../functors.md)\:\:[Infix\<callback\>](../../../../../Infix.md)\:\:[Intermediate](../../../Intermediate.md)\:\:operator\>
Defined in header [<xieite/functors/Infix.hpp>](../../../../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename RightArgument>
requires(std::invocable<decltype(callback), LeftArgument, const RightArgument&>)
constexpr std::invoke_result_t<decltype(callback), LeftArgument, const RightArgument&> operator>(const RightArgument& rightArgument) const;
```
#### 2)
```cpp
template<typename RightArgument>
requires(std::invocable<decltype(callback), LeftArgument, RightArgument&>)
constexpr std::invoke_result_t<decltype(callback), LeftArgument, RightArgument&> operator>(RightArgument& rightArgument);
```
