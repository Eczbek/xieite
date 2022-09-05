# gcufl::geometry::Circle::contains
```cpp
bool contains(const gcufl::geometry::Point point) const noexcept;
```
Checks whether a circle contains a point
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << gcufl::geometry::Circle({ 0, 0 }, 1).contains({ 0, 0 }) << '\n';
}
```
Output:
```
true
```
