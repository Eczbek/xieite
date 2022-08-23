# gcufl::geom::Point::rotate
```cpp
gcufl::geom::Point rotate(const double angle, const gcufl::geom::Point pivot = gcufl::geom::Point(0, 0)) const noexcept;
```
Rotates a copy of this point about a pivot.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>
#include <gcufl/math>

int main() {
	gcufl::geom::Point point1(0, 1);
	gcufl::geom::Point point2 = Point(1, 0).rotate(gcufl::math::degToRad(90));

	std::cout << (point1 == point2) << '\n';
}
```
Output:
```
true
```
