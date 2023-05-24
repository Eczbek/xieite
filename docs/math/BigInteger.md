# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::BigInteger`
Defined in header [`<xieite/math/BigInteger.hpp>`](../../include/xieite/math/BigInteger.hpp)

<br/>

A class for storing and operating on very large numbers.

<br/><br/>

## Synopsis

<br/>

```cpp
struct BigInteger final {
	template<std::integral Integral = int>
	constexpr BigInteger(Integral = 0);

	constexpr BigInteger(const xieite::math::BigInteger&);

	constexpr BigInteger(const xieite::concepts::RangeOf<bool> auto&, bool = false);

	constexpr BigInteger(std::string_view);

	constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator=(std::integral auto);

	template<xieite::concepts::Arithmetic Number>
	constexpr operator Number() const;

	constexpr operator bool() const;

	constexpr bool operator==(const xieite::math::BigInteger&) const;

	constexpr bool operator==(std::integral auto) const;

	constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger&) const;

	constexpr std::strong_ordering operator<=>(std::integral auto) const;

	constexpr xieite::math::BigInteger operator+() const;

	constexpr xieite::math::BigInteger operator+(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator+(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator+=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator+=(std::integral auto);

	constexpr xieite::math::BigInteger& operator++();

	constexpr xieite::math::BigInteger operator++(int);

	constexpr xieite::math::BigInteger operator-() const;

	constexpr xieite::math::BigInteger operator-(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator-(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator-=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator-=(std::integral auto);

	constexpr xieite::math::BigInteger& operator--();

	constexpr xieite::math::BigInteger operator--(int);

	constexpr xieite::math::BigInteger operator*(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator*(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator*=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator*=(std::integral auto);

	constexpr xieite::math::BigInteger operator/(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator/(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator/=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator/=(std::integral auto);

	constexpr xieite::math::BigInteger operator%(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator%(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator%=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator%=(std::integral auto);

	constexpr xieite::math::BigInteger operator~() const;

	constexpr xieite::math::BigInteger operator&(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator&(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator&=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator&=(std::integral auto);

	constexpr xieite::math::BigInteger operator|(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator|(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator|=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator|=(std::integral auto);

	constexpr xieite::math::BigInteger operator^(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator^(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator^=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator^=(std::integral auto);

	constexpr xieite::math::BigInteger operator<<(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator<<(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator<<=(std::integral auto);

	constexpr xieite::math::BigInteger operator>>(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger operator>>(std::integral auto) const;

	constexpr xieite::math::BigInteger& operator>>=(const xieite::math::BigInteger&);

	constexpr xieite::math::BigInteger& operator>>=(std::integral auto);

	constexpr xieite::math::BigInteger absolute() const;

	constexpr xieite::math::BigInteger power(xieite::math::BigInteger) const;

	constexpr xieite::math::BigInteger power(std::integral auto) const;

	constexpr xieite::math::BigInteger root(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger root(std::integral auto) const;

	constexpr const std::vector<bool>& data() const;

	constexpr std::string string() const;
};
```
### Member functions
- [`BigInteger`](../../docs/math/BigInteger/constructor.md)
- [`operator=`](../../docs/math/BigInteger/operatorAssign.md)
- [`operator typename`](../../docs/math/BigInteger/operatorCast.md)
- [`operator!`](../../docs/math/BigInteger/operatorNot.md)
- [`operator==`](../../docs/math/BigInteger/operatorEquals.md)
- [`operator<=>`](../../docs/math/BigInteger/operatorSpaceship.md)
- [`operator+`](../../docs/math/BigInteger/operatorAdd.md)
- [`operator+=`](../../docs/math/BigInteger/operatorAddAssign.md)
- [`operator++`](../../docs/math/BigInteger/operatorIncrement.md)
- [`operator-`](../../docs/math/BigInteger/operatorSubtract.md)
- [`operator-=`](../../docs/math/BigInteger/operatorSubtractAssign.md)
- [`operator--`](../../docs/math/BigInteger/operatorDecrement.md)
- [`operator*`](../../docs/math/BigInteger/operatorMultiply.md)
- [`operator*=`](../../docs/math/BigInteger/operatorMultiplyAssign.md)
- [`operator/`](../../docs/math/BigInteger/operatorDivide.md)
- [`operator/=`](../../docs/math/BigInteger/operatorDivideAssign.md)
- [`operator%`](../../docs/math/BigInteger/operatorModulo.md)
- [`operator%=`](../../docs/math/BigInteger/operatorModuloAssign.md)
- [`operator~`](../../docs/math/BigInteger/operatorBitwiseNot.md)
- [`operator&`](../../docs/math/BigInteger/operatorBitwiseAnd.md)
- [`operator&=`](../../docs/math/BigInteger/operatorBitwiseNotAssign.md)
- [`operator|`](../../docs/math/BigInteger/operatorBitwiseOr.md)
- [`operator|=`](../../docs/math/BigInteger/operatorBitwiseOrAssign.md)
- [`operator^`](../../docs/math/BigInteger/operatorBitwiseXor.md)
- [`operator^=`](../../docs/math/BigInteger/operatorBitwiseXorAssign.md)
- [`operator<<`](../../docs/math/BigInteger/operatorBitwiseShiftLeft.md)
- [`operator<<=`](../../docs/math/BigInteger/operatorBitwiseShiftLeftAssign.md)
- [`operator>>`](../../docs/math/BigInteger/operatorBitwiseShiftRight.md)
- [`operator>>=`](../../docs/math/BigInteger/operatorBitwiseShiftRightAssign.md)
- [`absolute`](../../docs/math/BigInteger/absolute.md)
- [`power`](../../docs/math/BigInteger/power.md)
- [`root`](../../docs/math/BigInteger/root.md)
- [`data`](../../docs/math/BigInteger/data.md)
- [`string`](../../docs/math/BigInteger/string.md)

<br/><br/>

## Example
```cpp
#include <iostream>
#include <xieite/math/BigInteger.hpp>

int main() {
	std::cout << xieite::math::BigInteger(99).power(99).string() << '\n';
}
```
Output:
```
369729637649726772657187905628805440595668764281741102430259972423552570455277523421410650010128232727940978889548326540119429996769494359451621570193644014418071060667659301384999779999159200499899
```

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)
- [`xieite::concepts::RangeOf`](../../docs/concepts/RangeOf.md)
