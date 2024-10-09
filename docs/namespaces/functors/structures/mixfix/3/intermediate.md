# [xieite](../../../../../xieite.md)\:\:[functors](../../../../../functors.md)\:\:[Mixfix<Return(LeftArgument, RightArgument)>](../../../mixfix.md)\:\:Intermediate\<\> \{\}
Defined in fragment [xieite:functors.Mixfix](../../../../../../src/functors/mixfix.cpp)

&nbsp;

## Description
An intermediate state for a mixfix thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename LeftArgumentReference>
struct Intermediate
: xieite::containers::MaybeCopyAssignable<false>, xieite::containers::MaybeMoveAssignable<false> {
	constexpr Intermediate(const Mixfix&, LeftArgumentReference&&) noexcept

    template<std::convertible_to<RightArgument> RightArgumentReference>
    friend constexpr Return operator/*   ->* * / % + - << >> <=> < <= > >= == != & ^ | && || *= /= %= += -= <<= >>= &= ^= |= ,   */(const Intermediate&&, RightArgumentReference&&)
    XIEITE_ARROW_BASE(/* ... */)
};
```
- [Intermediate\(\)](./structures/intermediate/1/operators/constructor.md)
- [operator???\<\>\(\)](./structures/intermediate/1/operators/how_did_we_get_here.md)

&nbsp;

## [Example](./operators/i_dont_even_know.md#Example)
