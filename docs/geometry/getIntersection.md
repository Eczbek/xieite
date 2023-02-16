# xieite::geometry::getIntersection
Declared in `<xieite/geometry/getIntersection.hpp>`

<br/>

Finds a possible intersection between two lines.

<br/><br/>

## Declaration
```cpp
template<std::derived_from<xieite::geometry::LineLike> L, std::derived_from<xieite::geometry::LineLike> M>
[[nodiscard]]
constexpr std::optional<xieite::geometry::Point> getIntersection(const L& lineLike1, const M& lineLike2) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getIntersection.hpp>

int main() {
	const xieite::geometry::Line line1({ 1, 0 }, { 1, 1 });
	const xieite::geometry::Line line2({ 0, 1 }, { 1, 1 });
	const xieite::geometry::Point intersection = xieite::geometry::getIntersection(line1, line2).value_or(xieite::geometry::Point(0, 0));
	std::cout << intersection.x << ' ' << intersection.y << '\n';
}
```
Output:
```
1 1
```
