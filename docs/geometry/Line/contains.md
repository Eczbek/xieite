# gcufl::geometry::Line::contains
```cpp
virtual bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether a line intersects a point.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << gcufl::geometry::Line({ 0, 0 }, { 1, 1 }).contains({ 5, 5 }) << '\n';
}
```
Output:
```
true
```
