# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Line
Defined in header [<xieite/geometry/Line.hpp>](../../include/xieite/geometry/Line.hpp)

&nbsp;

## Description
An class representing an infinite line

&nbsp;

## Synopsis
```cpp
struct Line {
    xieite::geometry::Point start;
    xieite::geometry::Point end;

    constexpr Line(xieite::geometry::Point, xieite::geometry::Point);

    constexpr Line(xieite::geometry::Point, double);

    constexpr bool operator==(const xieite::geometry::Line&) const;
};
```
#### Public members
## Contents
|- start
|- end
|- <a href="./Line/constructor.md">Line</a>
`- <a href="./Line/operatorEquals.md">operator==</a>
