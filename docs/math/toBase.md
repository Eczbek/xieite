# xieite::math::toBase
Declared in `<xieite/math/toBase.hpp>`

<br/>

Converts an integer to any base.

<br/><br/>

## Declaration
```cpp
template<std::integral N = int>
[[nodiscard]]
constexpr std::string toBase(N value, const unsigned int base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/toBase.hpp>

int main() {
	std::cout << xieite::math::toBase(12, 2) << '\n';
}
```
Output:
```
1100
```
