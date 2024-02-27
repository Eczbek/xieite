# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Interval
Defined in header [<xieite/math/interval.hpp>](../../../include/xieite/math/interval.hpp)

&nbsp;

## Description
A simple class for storing an interval between two numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number>
struct Interval {
    Number start;
    Number end;

    constexpr Interval(Number, Number);
};
```
##### Member variables
- start
- end
##### Member functions
- [Interval](./structures/interval/1/operators/constructor.md)
