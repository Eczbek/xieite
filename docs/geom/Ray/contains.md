# gcufl::geom::Ray::contains
```cpp
bool contains(const gcufl::geom::Point point) const noexcept;
```
Checks whether the ray intersects a point.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	std::cout
		<< std::boolalpha
		<< gcufl::geom::Ray({ 0, 0 }, { 1, 1 }).contains({ 5, 5 })
		<< '\n';
}
```
Output:
```
true
```
