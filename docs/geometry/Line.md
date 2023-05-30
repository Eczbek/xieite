# [xieite](../../README.md)::[geometry](../geometry.md)::Line
Defined in header [<xieite/geometry/Line.hpp>](../../include/xieite/geometry/Line.hpp)

<br/>

An class representing an infinite line

<br/><br/>

## Synopsis

<br/>

```cpp
struct Line {
	xieite::geometry::Point start;
	xieite::geometry::Point end;

	constexpr Line(xieite::geometry::Point, xieite::geometry::Point);

	constexpr Line(xieite::geometry::Point, double);

	constexpr bool operator==(const xieite::geometry::Line&) const;
};
```
### Public members
<pre><code>Line/
|- start
|- end
|- <a href="./Line/constructor.md">Line</a>
`- <a href="./Line/operatorEquals.md">operator==</a>
</code></pre>
