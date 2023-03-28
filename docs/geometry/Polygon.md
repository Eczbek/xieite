# xieite::geometry::Polygon
Defined in header `<xieite/geometry/Polygon.hpp>`

<br/>

A struct representing a polygon.

<br/><br/>

## Member objects
```cpp
std::vector<xieite::geometry::Point> points;
```

## Constructors
```cpp
constexpr Polygon(const std::vector<xieite::geometry::Point>& points) noexcept;
```

## Operators
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Polygon& other) const noexcept;
```
(`operator!=` is defined implicitly)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	std::cout << xieite::geometry::getArea(xieite::geometry::Polygon({
		{ 1.0, 0.0 },
		{ 2.0, 1.0 },
		{ 1.0, 2.0 },
		{ 0.0, 1.0 }
	})) << '\n';
}
```
Output:
```
1
```
