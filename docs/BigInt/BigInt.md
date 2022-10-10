# gcufl::BigInt::BigInt
Declared in `<gcufl/BigInt.hpp>`
```cpp
[[nodiscard]]
constexpr BigInt(const gcufl::BigInt& other) noexcept;

template<std::signed_integral N = int>
[[nodiscard]]
constexpr BigInt(N value = 0) noexcept;

template<std::unsigned_integral N>
[[nodiscard]]
constexpr BigInt(N value) noexcept;

template<std::forward_iterator I>
requires(std::convertible_to<typename I::value_type, bool>)
[[nodiscard]]
constexpr BigInt(const I begin, const I end, const bool sign = false) noexcept;
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
