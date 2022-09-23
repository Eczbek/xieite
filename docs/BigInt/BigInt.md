# gcufl::BigInt::BigInt
Declared in `<gcufl/BigInt.hpp>`
```cpp
BigInt(const gcufl::BigInt& other) noexcept;

BigInt(std::span<const std::uint8_t> digits, const bool sign = true) noexcept;

template<std::integral N = int>
BigInt(N value = 0) noexcept;
```
Creates a `BigInt` instance.
## Example
```cpp
#include <cstddef>
#include <gcufl/BigInt.hpp>
#include <iostream>
#include <vector>

int main() {
	std::cout << gcufl::BigInt(2984) << '\n'
		<< gcufl::BigInt(std::vector<std::uint8_t> { 3, 4, 9, 8, 0 }, false) << '\n'
		<< gcufl::BigInt(gcufl::BigInt()) << '\n';
}
```
Output:
```
2984
-34980
0
```
