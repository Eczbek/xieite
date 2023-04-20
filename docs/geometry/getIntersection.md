# `xieite::geometry::getIntersection`
Defined in header [`<xieite/geometry/getIntersection.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/geometry/getIntersection.hpp)

<br/>

Finds a possible intersection between two lines.

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr std::optional<xieite::geometry::Point> getIntersection(const xieite::concepts::LinearShape auto& linearShape1, const xieite::concepts::LinearShape auto& linearShape2) noexcept;
```
### Parameters
- `linearShape1` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `linearShape2` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- `std::optional` of `xieite::geometry::Point` - The intersection, if it exists

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getIntersection.hpp>

int main() {
	std::optional<xieite::geometry::Point> point = xieite::geometry::getIntersection(xieite::geometry::Line({ 1.0, 0.0 }, { 1.0, 1.0 }), xieite::geometry::Line({ 0.0, 1.0 }, { 1.0, 1.0 }));

	if (point.has_value())
		std::cout << '(' << point.value().x << ", " << point.value().y << ")\n";
}
```
Output:
```
(1, 1)
```

<br/><br/>

## See also
- [`xieite::geometry::Point`](https://github.com/Eczbek/xieite/tree/main/docs/geometry/Point.md)
