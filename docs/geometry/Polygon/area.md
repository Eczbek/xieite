# gcufl::geometry::Polygon::area
```cpp
double area() const noexcept;
```
Calculates the area of the polygon.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Polygon polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	});

	std::cout << polygon.area() << '\n';
}
```
Output:
```
4
```
