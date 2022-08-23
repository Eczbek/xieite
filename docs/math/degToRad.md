# gcufl::math::degToRad
```cpp
template <typename N>
double degToRad(const N degrees) noexcept;
```
Converts degrees to radians.
## Example
```cpp
#include <iostream>
#include <gcufl/math>

int main() {
	std::cout << gcufl::math::degToRad(180) << '\n';
}
```
Output:
```
3.14159
```
