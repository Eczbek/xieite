# xieite::math::fromBase
Defined in header `<xieite/math/fromBase.hpp>`

<br/>

Converts an integer string to base 10.

<br/><br/>

## Declarations
```cpp
template<std::integral N = int>
[[nodiscard]]
constexpr N fromBase(const std::string_view value, const unsigned int base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/math/fromBase.hpp>

int main() {
	std::cout << xieite::math::fromBase("g4h3", 21) << '\n';
}
```
Output:
```
150300
```
