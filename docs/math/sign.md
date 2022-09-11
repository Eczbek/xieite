# gcufl::math::sign
Declared in `<gcufl/math/sign.hpp>`
```cpp
template <gcufl::concepts::Arithmetic N>
constexpr int sign(const N value) noexcept;
```
Gets the sign of a number.
## Example
```cpp
#include <gcufl/math/sign.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::math::sign(17) << '\n'
		<< gcufl::math::sign(-44) << '\n'
		<< gcufl::math::sign(0) << '\n';
}
```
Output:
```
1
-1
0
```
