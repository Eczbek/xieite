# [xieite](../../../xieite.md)\:\:[functors](../../../functors.md)\:\:[Infix\<Result\(LeftArgument, RightArgument\), callback\>](../../Infix.md)\:\:Intermediate
Defined in header [<xieite/functors/Infix.hpp>](../../../../include/xieite/functors/Infix.hpp)

&nbsp;

## Description
An intermediate state for an infix.

&nbsp;

## Synopses
#### 1)
```cpp
struct Intermediate {
    constexpr Intermediate(const LeftArgument&);

    constexpr Result operator>(const RightArgument&) const;
};
```
##### Member functions
- [Intermediate](./structures/Intermediate/operators/constructor.md)
- [operator>](./structures/Intermediate/operators/more.md)
