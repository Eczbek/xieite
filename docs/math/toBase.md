# gcufl::math::toBase
Declared in `<gcufl/math/toBase.hpp>`
```cpp
template<std::integral N = int>
[[nodiscard]]
constexpr std::string toBase(N value, const unsigned int base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
Converts a base-10 integral to any base.
## Example
```cpp
#include <gcufl/math/toBase.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::math::toBase(12, 2) << '\n';
}
```
Output:
```
1100
```
