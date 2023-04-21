# [`xieite`](../../../README.md)`::`[`geometry`](../../../docs/geometry.md)`::`[`Line`](../../../docs/geoemtry/Line.md)`::Line`
Defined in header [`<xieite/geometry/Line.hpp>`](../../../include/xieite/geometry/Line.hpp)

<br/>

Constructs a `xieite::geometry::Line`.

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Line(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
### Parameters
- `start` - A `xieite::geometry::Point` copy, one intersection through which the infinite line passes
- `end` - A `xieite::geometry::Point` copy, another intersection through which the infinite line passes

<br/>

```cpp
constexpr Line(xieite::geometry::Point start, double angle) noexcept;
```
### Parameters
- `start` - A `xieite::geometry::Point` copy, an intersection through which the infinite line passes
- `angle` - A `double` copy, the line's angle

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
	xieite::geometry::Point start(0.0, 0.0);
	xieite::geometry::Point end(1.0, 1.0);

	xieite::geometry::Line line(start, end);

	std::cout << xieite::geometry::getAngle(line) << '\n';
}
```
Output:
```
0.785398
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../../docs/geometry/Point.md)
