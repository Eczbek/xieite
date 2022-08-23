# gcufl::math::radToDeg
```cpp
template <typename N>
double radToDeg(const N radians) noexcept;
```
Converts radians to degrees.
## Example
```cpp
#include <iostream>
#include <numbers>

int main() {
	std::cout << gcufl::math::radToDeg(std::numbers::pi) << '\n';
}
```
Output:
```
180
```
