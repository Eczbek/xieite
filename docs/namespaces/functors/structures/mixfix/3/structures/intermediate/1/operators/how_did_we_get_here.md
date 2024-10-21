# [xieite](../../../../../../../../../xieite.md)\:\:[functors](../../../../../../../../../functors.md)\:\:[Mixfix<Return(LeftArgument, RightArgument)>](../../../../../../../mixfix.md)\:\:[Intermediate<LeftArgumentReference>](../../../../intermediate.md)\:\:operator???\<\>\(\)
Defined in fragment [xieite:functors.Mixfix](../../../../../../../../../../src/functors/mixfix.cpp)

&nbsp;

## Description
Calls the underlying functor with both arguments.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::convertible_to<RightArgument> RightArgumentReference>
friend constexpr auto operator/*   ->* * / % + - << >> <=> < <= > >= == != & ^ | && || *= /= %= += -= <<= >>= &= ^= |= ,   */(const Intermediate&& intermediate, RightArgumentReference&& rightArgument)
XIEITE_ARROW(/* ... */)
```

&nbsp;

## [Example](../../../../operators/i_dont_even_know.md)
