# gcufl::math::approxEqual
```cpp
template <typename N>
bool approxEqual(const N value1, const N value2) noexcept;
```
Checks whether two numbers are approximately equal.
## Example
```cpp
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	std::cout << std::boolalpha << gcufl::math::approxEqual(0.3, 0.1 + 0.2) << '\n';
}
```
Output:
```
true
```
