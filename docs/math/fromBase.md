# xieite::math::fromBase
Declared in `<xieite/math/fromBase.hpp>`
```cpp
template<std::integral N = int>
[[nodiscard]]
constexpr N fromBase(const std::string_view value, const unsigned int base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```
Converts an integral from any base to base-10.
## Example
```cpp
#include <xieite/math/fromBase.hpp>
#include <iostream>

int main() {
	std::cout << xieite::math::fromBase("g4h3", 21) << '\n';
}
```
Output:
```
150300
```
