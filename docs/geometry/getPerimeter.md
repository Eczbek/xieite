# xieite::geometry::getPerimeter
Declared in `<xieite/geometry/getPerimeter.hpp>`

<br/>

Calculates the perimeter of a polygon.

<br/><br/>

## Declaration
```cpp
[[nodiscard]]
constexpr long double getPerimeter(const xieite::geometry::Polygon& polygon) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
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
