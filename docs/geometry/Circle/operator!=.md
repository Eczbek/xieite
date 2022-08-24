# gcufl::geometry::Circle::operator!=
```cpp
bool operator!=(const gcufl::geometry::Circle& other) const noexcept;
```
Compares two circles for inequality.
## Example
```cpp
#include <iostream>
#include <gcufl/geometry.hpp>

int main() {
	gcufl::geometry::Circle circle1({ 0, 0 }, 1);
	gcufl::geometry::Circle circle2({ 0, 0 }, 1);

	std::cout
		<< std::boolalpha
		<< (circle1 != circle2)
		<< '\n';
}
```
Output:
```
false
```
