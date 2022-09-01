# gcufl::BigInt::BigInt
```cpp
BigInt(const gcufl::BigInt& other) noexcept;

BigInt(std::span<const uint8_t> digits, const bool sign = true) noexcept;

template <std::integral N = int>
BigInt(N value = 0) noexcept;
```
Creates a BigInt for numbers larger than `long long`.
