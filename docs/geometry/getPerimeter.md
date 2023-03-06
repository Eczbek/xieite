# xieite::geometry::getPerimeter
Defined in header `<xieite/geometry/getPerimeter.hpp>`

<br/>

Calculates the perimeter of a polygon, or the sum of all its sides' lengths.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr long double getPerimeter(const xieite::geometry::Polygon& polygon) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getPerimeter.hpp>

int main() {
	const xieite::geometry::Polygon square({
		{ -1, -1 },
		{ 1, -1 },
		{ 1, 1 },
		{ -1, 1 }
	});
	std::cout << xieite::geometry::getPerimeter(square) << '\n';
}
```
Output:
```
8
```
