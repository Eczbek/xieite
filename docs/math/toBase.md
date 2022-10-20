# gcufl::math::toBase
Declared in `<gcufl/math/toBase.hpp>`
```cpp
template<std::unsigned_integral N = std::size_t>
[[nodiscard]]
constexpr std::string toBase(N value, const std::size_t base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
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
