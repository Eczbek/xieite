# xieite::geometry::getIntersection
Defined in header `<xieite/geometry/getIntersection.hpp>`

<br/>

Finds a possible intersection between two lines.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr std::optional<xieite::geometry::Point> getIntersection(const std::derived_from<xieite::geometry::LineLike> auto& lineLike1, const std::derived_from<xieite::geometry::LineLike> auto& lineLike2) noexcept;
```

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
		std::cout << point.value().x << ' ' << point.value().y << '\n';
}
```
Output:
```
1 1
```
