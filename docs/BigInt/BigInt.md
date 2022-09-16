# gcufl::BigInt::BigInt
Declared in `<gcufl/BigInt.hpp>`
```cpp
BigInt(const gcufl::BigInt& other) noexcept;

BigInt(std::span<const std::uint8_t> digits, const bool sign = true) noexcept;

template<std::integral N = int>
BigInt(N value = 0) noexcept
: sign(value >= 0) {
	value = std::abs(value);
	do {
		digits.push_back(value % 10);
		value /= 10;
	} while (value);
}
```
Creates a `BigInt` instance.
