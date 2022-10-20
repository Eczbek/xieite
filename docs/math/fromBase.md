# gcufl::math::fromBase
Declared in `<gcufl/math/fromBase.hpp>`
```cpp
template<std::unsigned_integral N = std::size_t>
[[nodiscard]]
constexpr N fromBase(const std::string_view value, const std::size_t base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
Converts an integral from any base to base-10.
## Example
```cpp
#include <gcufl/math/fromBase.hpp>
#include <iostream>

int main() {
	std::cout << gcufl::math::fromBase("g4h3", 21) << '\n';
}
```
Output:
```
150300
```
