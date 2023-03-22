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
	const xieite::geometry::Line line1({ 1.0, 0.0 }, { 1.0, 1.0 });
	const xieite::geometry::Line line2({ 0.0, 1.0 }, { 1.0, 1.0 });
	const xieite::geometry::Point intersection = xieite::geometry::getIntersection(line1, line2).value_or(xieite::geometry::Point());
	std::cout << intersection.x << ' ' << intersection.y << '\n';
}
```
Output:
```
1 1
```
