# gcufl::math::radians
```cpp
template <gcufl::traits::Arithmetic N>
double radians(const N degrees) noexcept;
```
Converts degrees to radians.
## Example
```cpp
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::math::radians(180) << '\n';
}
```
Output:
```
3.14159
```
