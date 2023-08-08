# [xieite](../xieite.md)\:\:[math](../math.md)\:\:Interval
Defined in header [<xieite/math/Interval.hpp>](../../include/xieite/math/Interval.hpp)

&nbsp;

## Description
A simple class for storing an interval between two numbers

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
struct Interval {
    Arithmetic start;
    Arithmetic end;

    constexpr Interval(Arithmetic, Arithmetic);
};
```
#### Public members
## Contents
|- start
|- end
`- <a href="./Interval/constructor.md">Interval</a>
