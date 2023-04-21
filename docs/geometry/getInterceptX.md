# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getInterceptX`
Defined in header [`<xieite/geometry/getInterceptX.hpp>`](../../include/xieite/geometry/getInterceptY.hpp)

<br/>

Finds an optional point where a line intercepts the X axis.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::optional<xieite::geometry::Point> getInterceptX(const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- `std::optional` of `xieite::geometry::Point` - The X-intercept, if it exists

<br/><br/>

## Example
```cpp
#include <iostream>
#include <optional>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getInterceptX.hpp>

int main() {
	xieite::geometry::Point start(1.0, 2.0);
	xieite::geometry::Point end(2.0, 1.0);

	xieite::geometry::Line line(start, end);

	std::optional<xieite::geometry::Point> point = xieite::geometry::getInterceptX(line);

	if (point.has_value()) {
		xieite::geometry::Point value = point.value();

		std::cout << '(' << value.x << ", " << value.y << ")\n";
	}
}
```
Output:
```
(3, 0)
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)
