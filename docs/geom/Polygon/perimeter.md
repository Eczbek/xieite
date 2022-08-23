# gcufl::geom::Polygon::perimeter
```cpp
double perimeter() const noexcept;
```
Calculates the perimeter of the polygon.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	gcufl::geom::Polygon polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	});

	std::cout << polygon.perimeter() << '\n';
}
```
Output:
```
8
```
