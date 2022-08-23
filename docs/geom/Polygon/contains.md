# gcufl::geom::Polygon::contains
```cpp
bool contains(const gcufl::geom::Point point) const noexcept;
```
Checks whether the polygon contains a point.
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

	std::cout
		<< std::boolalpha
		<< polygon.contains({ 1, 1 })
		<< '\n';
}
```
Output:
```
true
```
