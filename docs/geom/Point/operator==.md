# gcufl::geom::Point::operator==
```cpp
bool operator==(const gcufl::geom::Point other) const noexcept;
```
Compares two points for equality. Uses `gcufl::math::approxEqual` to account for rounding errors.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>

int main() {
	gcufl::geom::Point point1(0.3, 0);
	gcufl::geom::Point point2(0.1 + 0.2, 0);

	std::cout << (point1 == point2) << '\n';
}
```
Output:
```
true
```
