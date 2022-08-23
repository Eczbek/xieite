# gcufl::geom::Polygon::operator==
```cpp
bool operator==(const gcufl::geom::Polygon& other) const noexcept;
```
Compares two polygons for equality.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	gcufl::geom::Polygon polygon1({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	});
	gcufl::geom::Polygon polygon2({
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
true
```
