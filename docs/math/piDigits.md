# xieite::math::piDigits
Defined in header `<xieite/math/piDigits.hpp>`

<br/>

Calculates digits of Pi.

<br/><br/>

## Declarations
```cpp
template<std::integral Integral = int>
std::vector<Integral> piDigits(std::size_t digits) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/piDigits.hpp>

int main() {
	for (int digit : xieite::math::piDigits(50))
		std::cout << digit;
	std::cout << '\n';
}
```
Output:
```
31415926535897932384626433832795028841971693993751
```
