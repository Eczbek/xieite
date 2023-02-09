# xieite::geometry::getSlope
Declared in `<xieite/geometry/getSlope.hpp>`

<br/>

Calculates the slope of a line or between two points.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr long double getSlope(const xieite::geometry::Point& point1, const xieite::geometry::Point& point2) noexcept;
```
```cpp
template<std::derived_from<xieite::geometry::AbstractLine> LineLike>
[[nodiscard]]
constexpr long double getSlope(const LineLike& lineLike) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getSlope.hpp>

int main() {
	const xieite::geometry::Line line({ 0, 0 }, { 2, 3 });
	std::cout << xieite::geometry::getSlope(line) << '\n';
}
```
Output:
```
1.5
```
