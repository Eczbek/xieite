# xieite::BigInt
Declared in `<xieite/BigInt.hpp>`

<br/>

A class for storing and operating on very large numbers.

<br/><br/>

## Constructors
```cpp
constexpr BigInt(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::signed_integral N = int>
constexpr BigInt(N value = 0) noexcept;
```
```cpp
template<std::unsigned_integral N>
constexpr BigInt(N value) noexcept;
```
```cpp
template<std::forward_iterator I>
requires(std::convertible_to<typename I::value_type, bool>)
constexpr BigInt(const I begin, const I end, const bool sign = false) noexcept;
```
```cpp
constexpr BigInt(std::string_view value) noexcept;
```

## Operators
```cpp
constexpr xieite::BigInt& operator=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator=(const N value) noexcept;
```
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
constexpr operator N() const noexcept;
```
```cpp
[[nodiscard]]
constexpr operator bool() const noexcept;
```
```cpp
[[nodiscard]]
constexpr bool operator!() const noexcept;
```
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr bool operator==(const N value) const noexcept;
```
```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const N value) const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator+() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator+(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator+(const N value) const noexcept;
```
```cpp
constexpr xieite::BigInt& operator+=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator+=(const N value) noexcept;
```
```cpp
constexpr xieite::BigInt& operator++() noexcept;
```
```cpp
constexpr xieite::BigInt operator++(int) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator-() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator-(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator-(const N value) const noexcept;
```
```cpp
constexpr xieite::BigInt& operator-=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator-=(const N value) noexcept;
```
```cpp
constexpr xieite::BigInt& operator--() noexcept;
```
```cpp
constexpr xieite::BigInt operator--(int) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator*(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator*(const N value) const noexcept;
```
```cpp
constexpr xieite::BigInt& operator*=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator*=(const N value) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator/(xieite::BigInt other) const;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator/(const N value) const;
```
```cpp
constexpr xieite::BigInt& operator/=(const xieite::BigInt& other);
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator/=(const N value);
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator%(xieite::BigInt other) const;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator%(const N value) const;
```
```cpp
constexpr xieite::BigInt& operator%=(const xieite::BigInt& other);
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator%=(const N value);
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator~() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator&(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator&(const N value) const noexcept;
```
```cpp
constexpr xieite::BigInt& operator&=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator&=(const N value) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator|(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator|(const N value) const noexcept;
```
```cpp
constexpr xieite::BigInt& operator|=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator|=(const N value) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator^(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator^(const N value) const noexcept;
```
```cpp
constexpr xieite::BigInt& operator^=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator^=(const N value) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator<<(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator<<(const N value) const noexcept;
```
```cpp
constexpr xieite::BigInt& operator<<=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt& operator<<=(const N value) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt operator>>(const xieite::BigInt& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt operator>>(const N value) const noexcept;
```
```cpp
constexpr xieite::BigInt operator>>=(const xieite::BigInt& other) noexcept;
```
```cpp
template<std::integral N>
constexpr xieite::BigInt operator>>=(const N value) noexcept;
```
(`operator<`, `operator>`, `operator!=`, `operator<=`, and `operator>=` are defined implicitly)

## Other Methods
```cpp
[[nodiscard]]
constexpr xieite::BigInt abs() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt pow(xieite::BigInt other) const;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt pow(const N value) const;
```
```cpp
[[nodiscard]]
constexpr xieite::BigInt root(const xieite::BigInt& other) const;
```
```cpp
template<std::integral N>
[[nodiscard]]
constexpr xieite::BigInt root(const N value) const;
```
```cpp
[[nodiscard]]
constexpr const std::vector<bool>& data() const noexcept;
```
```cpp
[[nodiscard]]
constexpr std::string string() const noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/BigInt.hpp>

int main() {
	std::cout << xieite::BigInt(99).pow(99).string() << '\n';
}
```
Output:
```
369729637649726772657187905628805440595668764281741102430259972423552570455277523421410650010128232727940978889548326540119429996769494359451621570193644014418071060667659301384999779999159200499899
```
