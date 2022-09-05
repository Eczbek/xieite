# gcufl::geometry::Ray::operator==
```cpp
bool operator==(const gcufl::geometry::Ray& other) const noexcept;
```
Compares two rays for equality.
## Example
```cpp
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	gcufl::geometry::Ray ray1({ 0, 0 }, { 1, 1 });
	gcufl::geometry::Ray ray2({ 3, 3 }, gcufl::math::radians(45));

	std::cout << std::boolalpha << (ray1 == ray2) << '\n';
}
```
Output:
```
false
```
