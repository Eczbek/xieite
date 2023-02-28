# xieite::math::BigInteger
Defined in header `<xieite/math/BigInteger.hpp>`

<br/>

A class for storing and operating on very large numbers.

<br/><br/>

## Constructors
```cpp
BigInteger(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::signed_integral N = int>
BigInteger(N value = 0) noexcept;
```
```cpp
template<std::unsigned_integral N>
BigInteger(N value) noexcept;
```
```cpp
template<std::forward_iterator I>
requires(std::convertible_to<typename I::value_type, bool>)
BigInteger(const I begin, const I end, const bool sign = false) noexcept;
```
```cpp
BigInteger(const std::string_view value);
```

## Operators
```cpp
xieite::math::BigInteger& operator=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator=(const N value) noexcept;
```
```cpp
template<xieite::concepts::Arithmetic N>
[[nodiscard]]
operator N() const noexcept;
```
```cpp
[[nodiscard]]
operator bool() const noexcept;
```
```cpp
[[nodiscard]]
bool operator!() const noexcept;
```
```cpp
[[nodiscard]]
bool operator==(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
bool operator==(const N value) const noexcept;
```
```cpp
[[nodiscard]]
std::strong_ordering operator<=>(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
std::strong_ordering operator<=>(const N value) const noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator+() const noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator+(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator+(const N value) const noexcept;
```
```cpp
xieite::math::BigInteger& operator+=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator+=(const N value) noexcept;
```
```cpp
xieite::math::BigInteger& operator++() noexcept;
```
```cpp
xieite::math::BigInteger operator++(int) noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator-() const noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator-(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator-(const N value) const noexcept;
```
```cpp
xieite::math::BigInteger& operator-=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator-=(const N value) noexcept;
```
```cpp
xieite::math::BigInteger& operator--() noexcept;
```
```cpp
xieite::math::BigInteger operator--(int) noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator*(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator*(const N value) const noexcept;
```
```cpp
xieite::math::BigInteger& operator*=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator*=(const N value) noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator/(xieite::math::BigInteger other) const;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator/(const N value) const;
```
```cpp
xieite::math::BigInteger& operator/=(const xieite::math::BigInteger& other);
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator/=(const N value);
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator%(xieite::math::BigInteger other) const;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator%(const N value) const;
```
```cpp
xieite::math::BigInteger& operator%=(const xieite::math::BigInteger& other);
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator%=(const N value);
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator~() const noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator&(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator&(const N value) const noexcept;
```
```cpp
xieite::math::BigInteger& operator&=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator&=(const N value) noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator|(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator|(const N value) const noexcept;
```
```cpp
xieite::math::BigInteger& operator|=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator|=(const N value) noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator^(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator^(const N value) const noexcept;
```
```cpp
xieite::math::BigInteger& operator^=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator^=(const N value) noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator<<(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator<<(const N value) const noexcept;
```
```cpp
xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger& operator<<=(const N value) noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger operator>>(const xieite::math::BigInteger& other) const noexcept;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger operator>>(const N value) const noexcept;
```
```cpp
xieite::math::BigInteger operator>>=(const xieite::math::BigInteger& other) noexcept;
```
```cpp
template<std::integral N>
xieite::math::BigInteger operator>>=(const N value) noexcept;
```
(`operator<`, `operator>`, `operator!=`, `operator<=`, and `operator>=` are defined implicitly)

## Other methods
```cpp
[[nodiscard]]
xieite::math::BigInteger abs() const noexcept;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger pow(xieite::math::BigInteger other) const;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger pow(const N value) const;
```
```cpp
[[nodiscard]]
xieite::math::BigInteger root(const xieite::math::BigInteger& other) const;
```
```cpp
template<std::integral N>
[[nodiscard]]
xieite::math::BigInteger root(const N value) const;
```
```cpp
[[nodiscard]]
const std::vector<bool>& data() const noexcept;
```
```cpp
[[nodiscard]]
std::string string() const noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream> // std::cout
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << xieite::math::BigInteger(99).pow(99).string() << '\n';
}
```
Output:
```
369729637649726772657187905628805440595668764281741102430259972423552570455277523421410650010128232727940978889548326540119429996769494359451621570193644014418071060667659301384999779999159200499899
```
([Checked with WolframAlpha](https://www.wolframalpha.com/input?i=99^99))
