# gcufl::math::wrap
```cpp
template <typename N>
N wrap(const N value, const N max, const N min = 0) noexcept;
```
Wraps a number between limits.
## Example
```cpp
#include <iostream>
#include <gcufl/math.hpp>

int main() {
	std::cout << gcufl::math::wrap(6, 5, -2) << '\n';
}
```
Output:
```
-1
```
