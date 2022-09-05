# gcufl::math::toBase
```cpp
template <std::integral N>
std::string toBase(N value, const int base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
Converts a base-10 number to any base.
## Example
```cpp
#include <gcufl/math.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::math::toBase(16, 17) << '\n';
}
```
Output:
```
g
```
