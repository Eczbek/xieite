# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Line
Defined in header [<xieite/geometry/line.hpp>](../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
An structure for representing an infinite line.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Line {
    xieite::geometry::Point start;
    xieite::geometry::Point end;

    constexpr Line(xieite::geometry::Point, xieite::geometry::Point);

    constexpr Line(xieite::geometry::Point, double);

    friend constexpr bool operator==(const xieite::geometry::Line&, const xieite::geometry::Line&);

    constexpr double angle() const;

    constexpr bool containsPoint(xieite::geometry::Point) const;

    constexpr double length() const;

    constexpr double slope() const;
};
```
##### Member variables
- start
- end
##### Member functions
- [Line](./structures/line/1/operators/constructor.md)
- [operator==](./structures/line/1/operators/equal.md)
- [angle](./structures/line/1/angle.md)
- [containsPoint](./structures/line/1/contains_point.md)
- [length](./structures/line/1/length.md)
- [slope](./structures/line/1/slope.md)
