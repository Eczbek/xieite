# gcufl::geometry::Polygon::operator!=
```cpp
bool operator!=(const gcufl::geometry::Polygon& other) const noexcept;
```
Compares two polygons for inequality.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Polygon polygon1({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	});
	gcufl::geometry::Polygon polygon2({
		{ 2, 2 },
		{ 2, 0 },
		{ 0, 0 },
		{ 0, 2 }
	});

	std::cout
		<< std::boolalpha
		<< (polygon1 == polygon2)
		<< '\n';
}
```
Output:
```
false
```
