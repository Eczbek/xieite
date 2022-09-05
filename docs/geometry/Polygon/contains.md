# gcufl::geometry::Polygon::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether a polygon contains a point.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << gcufl::geometry::Polygon({
		{ 0, 0 },
		{ 2, 0 },
		{ 2, 2 },
		{ 0, 2 }
	}).contains({ 1, 1 }) << '\n';
}
```
Output:
```
true
```
