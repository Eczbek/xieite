# gcufl::geom::Ray::operator!=
```cpp
bool operator!=(const gcufl::geom::Ray& other) const noexcept;
```
Compares two rays for inequality.
## Example
```cpp
#include <iostream>
#include <gcufl/geom>
#include <gcufl/math>

int main() {
	gcufl::geom::Ray ray1({ 0, 0 }, { 1, 1 });
	gcufl::geom::Ray ray2({ 3, 3 }, gcufl::math::degToRad(45));

	std::cout << (ray1 != ray2) << '\n';
}
```
Output:
```
true
```
