# gcufl::geometry::Ray::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether the ray intersects a point.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Ray ray({ 0, 0 }, { 1, 1 });

	std::cout << std::boolalpha << ray.contains({ 5, 5 }) << '\n';
}
```
Output:
```
true
```
