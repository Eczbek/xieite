# xieite::math::piDigits
Defined in header `<xieite/math/piDigits.hpp>`

<br/>

Calculates digits of Pi.

<br/><br/>

## Declarations
```cpp
template<std::integral N>
std::vector<N> piDigits(const std::size_t digits) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/math/piDigits.hpp>

int main() {
	for (const int digit : xieite::math::piDigits(50))
		std::cout << digit;
	std::cout << '\n';
}
```
Output:
```
31415926535897932384626433832795028841971693993751
```
