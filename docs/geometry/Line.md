# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Line
Defined in header [<xieite/geometry/Line.hpp>](../../include/xieite/geometry/Line.hpp)

&nbsp;

## Description
An class representing an infinite line.

&nbsp;

## Synopses
#### 1)
```cpp
struct Line {
    xieite::geometry::Point start;
    xieite::geometry::Point end;

    constexpr Line(xieite::geometry::Point, xieite::geometry::Point);

    constexpr Line(xieite::geometry::Point, double);

    constexpr bool operator==(const xieite::geometry::Line&) const;
};
```
##### Member variables
- start
- end
##### Member functions
- [Line](./Line/1/constructor.md)
- [operator==](./Line/1/operatorEquals.md)
