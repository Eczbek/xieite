# xieite::geometry::Polygon
Defined in header `<xieite/geometry/Polygon.hpp>`

<br/>

A struct representing a polygon.

<br/><br/>

## Member objects
```cpp
std::vector<xieite::geometry::Point> points;
```

## Constructor
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
#include <iostream> // std::cout
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
	const xieite::geometry::Polygon diamond({
		{ 1, 0 },
		{ 2, 1 },
		{ 1, 2 },
		{ 0, 1 }
	});
	std::cout << xieite::geometry::getArea(diamond) << '\n';
}
```
Output:
```
1
```
