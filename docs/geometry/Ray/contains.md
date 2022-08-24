# gcufl::geometry::Ray::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether the ray intersects a point.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	std::cout
		<< std::boolalpha
		<< gcufl::geometry::Ray({ 0, 0 }, { 1, 1 }).contains({ 5, 5 })
		<< '\n';
}
```
Output:
```
true
```
