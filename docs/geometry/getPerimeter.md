# xieite::geometry::getPerimeter
Defined in header `<xieite/geometry/getPerimeter.hpp>`

<br/>

Calculates the perimeter of a polygon, or the sum of all its sides' lengths.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr double getPerimeter(const xieite::geometry::Polygon& polygon) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getPerimeter.hpp>

int main() {
	std::cout << xieite::geometry::getPerimeter(xieite::geometry::Polygon({
		{ -1.0, -1.0 },
		{ 1.0, -1.0 },
		{ 1.0, 1.0 },
		{ -1.0, 1.0 }
	})) << '\n';
}
```
Output:
```
8
```
