# `xieite::geometry::getInterceptX`
Defined in header [`<xieite/geometry/getInterceptX.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/getInterceptY.hpp)

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
	std::optional<xieite::geometry::Point> point = xieite::geometry::getInterceptX(xieite::geometry::Line({ 1.0, 2.0 }, { 2.0, 1.0 }));

	if (point.has_value())
		std::cout << '(' << point.value().x << ", " << point.value().y << ")\n";
}
```
Output:
```
(3, 0)
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point.md)
