# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::Line`
Defined in header [`<xieite/geometry/Line.hpp>`](../../include/xieite/geometry/Line.hpp)

<br/>

An struct representing an infinite line.

<br/><br/>

## Synopsis

<br/>

```cpp
struct Line final {
	xieite::geometry::Point start;
	xieite::geometry::Point end;

	constexpr Line(xieite::geometry::Point, xieite::geometry::Point);

	constexpr Line(xieite::geometry::Point, double);

	constexpr bool operator==(const xieite::geometry::Line&) const;
};
```
### Member objects
- `start` - A `xieite::geometry::Point`
- `end` - Another `xieite::geometry::Point`
### Member functions
- [`Line`](../../docs/geometry/Line/constructor.md)
- [`operator==`](../../docs/geometry/Line/operatorEquals.md)

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../docs/geometry/Point.hpp)
