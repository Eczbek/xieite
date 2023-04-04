# xieite::math::Integer
Defined in header `<xieite/math/Integer.hpp>`

<br/>

Allows creation of integer types of any bit size. All mathematical operators are defined.

<br/><br/>

## Template parameters
```cpp
template<std::size_t bits, bool sign>
```

## Constructors
```cpp
constexpr Integer(const std::integral auto value = 0) noexcept;
```

## Operators
```cpp
constexpr xieite::math::Integer<bits, sign> operator=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
template<std::integral Integral>
[[nodiscard]]
constexpr operator Integral() const noexcept;
```
```cpp
template<std::size_t otherBits, bool otherSign>
[[nodiscard]]
constexpr operator xieite::math::Integer<otherBits, otherSign>() const noexcept;
```
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
[[nodiscard]]
constexpr std::strong_ordering operator<=>(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator+() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator+(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator+=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator++() noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator++(int) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator-() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator-(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator-=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator--() noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator--(int) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator*(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator*=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator/(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator/=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator%(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator%=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator~() const noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator|(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator|=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator&(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator&=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator^(const xieite::math::Integer<bits, sign> other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator^=(const xieite::math::Integer<bits, sign> other) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator<<(const std::size_t other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator<<=(const std::size_t other) noexcept;
```
```cpp
[[nodiscard]]
constexpr xieite::math::Integer<bits, sign> operator>>(const std::size_t other) const noexcept;
```
```cpp
constexpr xieite::math::Integer<bits, sign> operator>>=(const std::size_t other) noexcept;
```
```cpp
friend constexpr std::ostream& operator<<(std::ostream& outStream, const xieite::math::Integer<bits, sign> self) noexcept;
```
```cpp
friend constexpr std::istream& operator>>(std::istream& inStream, xieite::math::Integer<bits, sign> self) noexcept;
```

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/Integer.hpp>

using Int3 = xieite::math::Integer<3, true>;
using UInt17 = xieite::math::Integer<17, false>;

int main() {
	Int3 a = 5;
	UInt17 b = 5;

	std::cout << std::boolalpha << (a == b) << '\n';
}
```
Output:
```
true
```
