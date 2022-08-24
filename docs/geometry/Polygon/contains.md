# gcufl::geometry::Polygon::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether the polygon contains a point.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Polygon polygon({
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
