# gcufl::math::degrees
```cpp
template <typename N>
double degrees(const N radians) noexcept;
```
Converts radians to degrees.
## Example
```cpp
#include <iostream>
#include <numbers>
#include <gcufl/math.hpp>

int main() {
	std::cout << gcufl::math::degrees(std::numbers::pi) << '\n';
}
```
Output:
```
180
```
