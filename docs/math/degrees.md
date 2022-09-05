# gcufl::math::degrees
```cpp
template <gcufl::traits::Arithmetic N>
double degrees(const N radians) noexcept;
```
Converts radians to degrees.
## Example
```cpp
#include <gcufl/math.hpp>
#include <iostream>
#include <numbers>

int main() {
	std::cout << gcufl::math::degrees(std::numbers::pi) << '\n';
}
```
Output:
```
180
```
