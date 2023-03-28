# xieite::geometry::getSlope
Defined in header `<xieite/geometry/getSlope.hpp>`

<br/>

Calculates the slope of a line or between two points.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr double getSlope(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
```cpp
[[nodiscard]]
constexpr double getSlope(const std::derived_from<xieite::geometry::LineLike> auto& lineLike) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getSlope.hpp>

int main() {
	std::cout << xieite::geometry::getSlope(xieite::geometry::Line({ 0.0, 0.0 }, { 2.0, 3.0 })) << '\n';
}
```
Output:
```
1.5
```
