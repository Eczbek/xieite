# [xieite](../../../xieite.md)\:\:[functors](../../../functors.md)\:\:[Infix\<Callback\>](../../Infix.md)\:\:Intermediate
Defined in header [<xieite/functors/Infix.hpp>](../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Description
An intermediate state for an infix.

&nbsp;

## Synopsis
```cpp
struct Intermediate {
	constexpr Intermediate(const LeftArgument&);

	constexpr Result operator>(const RightArgument&) const;
};
```
##### Member functions
- [Intermediate](./Intermediate/constructor.md)
- [operator>](./Intermediate/operatorMore.md)
