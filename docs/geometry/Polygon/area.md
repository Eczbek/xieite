# gcufl::geometry::Polygon::area
```cpp
double area() const noexcept;
```
Calculates the area of a polygon.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::geometry::Polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	}).area() << '\n';
}
```
Output:
```
4
```
