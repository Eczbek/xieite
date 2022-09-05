# gcufl::geometry::Point::operator!=
```cpp
bool operator!=(const gcufl::geometry::Point other) const noexcept;
```
Compares two points for inequality. Uses `gcufl::math::approxEqual` to account for rounding errors.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Point point1(0.3, 0);
	gcufl::geometry::Point point2(0.1 + 0.2, 0);

	std::cout << std::boolalpha << (point1 != point2) << '\n';
}
```
Output:
```
false
```
