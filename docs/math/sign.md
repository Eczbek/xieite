# gcufl::math::sign
```cpp
template <typename N>
int sign(const N value) noexcept;
```
Gets the sign of a number.
## Example
```cpp
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	std::cout
		<< gcufl::math::sign(17) << '\n'
		<< gcufl::math::sign(0) << '\n'
		<< gcufl::math::sign(-44) << '\n';
}
```
Output:
```
1
0
-1
```
