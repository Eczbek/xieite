# gcufl::math::fromBase
Defined in `<gcufl/math/fromBase.hpp>`
<br/><br/>
```cpp
template <std::integral N = int>
constexpr N fromBase(std::string_view value, const int base, std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
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
