# gcufl::geometry::Line::operator==
```cpp
bool operator==(const gcufl::geometry::Line& other) const noexcept;
```
Compares two lines for equality.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Line line1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Line line2({ 3, 3 }, gcufl::math::radians(45));

	std::cout << std::boolalpha << (line1 == line2) << '\n';
}
```
Output:
```
true
```
