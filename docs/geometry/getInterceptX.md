# xieite::geometry::getInterceptX
Defined in header `<xieite/geometry/getInterceptX.hpp>`

<br/>

Finds an optional point where a line intercepts the X axis.

<br/><br/>

## Declarations
```cpp
template<std::derived_from<xieite::geometry::LineLike> L>
[[nodiscard]]
constexpr std::optional<xieite::geometry::Point> getInterceptX(const L& lineLike) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <optional> // std::optional
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getInterceptX.hpp>

int main() {
	const xieite::geometry::Line line({ 1, 2 }, { 2, 1 });
	const std::optional<xieite::geometry::Point> point = xieite::geometry::getInterceptX(line);
	if (point.has_value())
		std::cout << '(' << point.value().x << ", " << point.value().y << ")\n";
}
```
Output:
```
(3, 0)
```
