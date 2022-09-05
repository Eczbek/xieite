# gcufl::geometry::Ellipse::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether an ellipse contains a point
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << gcufl::geometry::Ellipse({ 0, 0 }, { 1, 2 }).contains({ 0, 0 }) << '\n';
}
```
Output:
```
true
```
