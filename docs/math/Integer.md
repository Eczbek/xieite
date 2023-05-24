# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::Integer`
Defined in header [`<xieite/math/Integer.hpp>`](../../include/xieite/math/Integer.hpp)

<br/>

Allows creation of integer types of any bit size. All mathematical operators are defined.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::size_t bits, bool sign>
struct Integer<bits, sign> final {
	template<std::integral Integral = int>
	constexpr Integer<bits, sign>(Integral = 0);

	constexpr xieite::math::Integer<bits, sign> operator=(xieite::math::Integer<bits, sign>);

	template<std::integral Integral>
	constexpr operator Integral() const;

	template<std::size_t integerBits, bool integerSign>
	constexpr operator xieite::math::Integer<integerBits, integerSign>() const;

	constexpr bool operator==(xieite::math::Integer<bits, sign>) const;

	constexpr std::strong_ordering operator<=>(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator+() const;

	constexpr xieite::math::Integer<bits, sign> operator+(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator+=(xieite::math::Integer<bits, sign>);

	constexpr xieite::math::Integer<bits, sign> operator++();

	constexpr xieite::math::Integer<bits, sign> operator++(int);

	constexpr xieite::math::Integer<bits, sign> operator-() const;

	constexpr xieite::math::Integer<bits, sign> operator-(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator-=(xieite::math::Integer<bits, sign>);

	constexpr xieite::math::Integer<bits, sign> operator--();

	constexpr xieite::math::Integer<bits, sign> operator--(int);

	constexpr xieite::math::Integer<bits, sign> operator*(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator*=(xieite::math::Integer<bits, sign>);

	constexpr xieite::math::Integer<bits, sign> operator/(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator/=(xieite::math::Integer<bits, sign>);

	constexpr xieite::math::Integer<bits, sign> operator%(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator%=(xieite::math::Integer<bits, sign>);

	constexpr xieite::math::Integer<bits, sign> operator~() const;

	constexpr xieite::math::Integer<bits, sign> operator&(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator&=(xieite::math::Integer<bits, sign>);

	constexpr xieite::math::Integer<bits, sign> operator|(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator|=(xieite::math::Integer<bits, sign>);

	constexpr xieite::math::Integer<bits, sign> operator^(xieite::math::Integer<bits, sign>) const;

	constexpr xieite::math::Integer<bits, sign> operator^=(xieite::math::Integer<bits, sign>);

	constexpr xieite::math::Integer<bits, sign> operator<<(std::size_t) const;

	constexpr xieite::math::Integer<bits, sign> operator<<=(std::size_t);

	constexpr xieite::math::Integer<bits, sign> operator>>(std::size_t) const;

	constexpr xieite::math::Integer<bits, sign> operator>>=(std::size_t);

	friend constexpr std::ostream& operator<<(std::ostream&, xieite::math::Integer<bits, sign>);

	friend constexpr std::istream& operator>>(std::istream&, xieite::math::Integer<bits, sign>&);
};
```
### Template parameters
- `bits` - A `std::size_t` copy, how many bits the type can use
- `sign` - A `bool` copy, whether or not the type is signed
### Member functions
- [`Integer`](../../docs/math/Integer/constructor.md)
- [`operator=`](../../docs/math/Integer/operatorAssign.md)
- [`operator typename`](../../docs/math/Integer/operatorCast.md)
- [`operator!`](../../docs/math/Integer/operatorNot.md)
- [`operator==`](../../docs/math/Integer/operatorEquals.md)
- [`operator<=>`](../../docs/math/Integer/operatorSpaceship.md)
- [`operator+`](../../docs/math/Integer/operatorAdd.md)
- [`operator+=`](../../docs/math/Integer/operatorAddAssign.md)
- [`operator++`](../../docs/math/Integer/operatorIncrement.md)
- [`operator-`](../../docs/math/Integer/operatorSubtract.md)
- [`operator-=`](../../docs/math/Integer/operatorSubtractAssign.md)
- [`operator--`](../../docs/math/Integer/operatorDecrement.md)
- [`operator*`](../../docs/math/Integer/operatorMultiply.md)
- [`operator*=`](../../docs/math/Integer/operatorMultiplyAssign.md)
- [`operator/`](../../docs/math/Integer/operatorDivide.md)
- [`operator/=`](../../docs/math/Integer/operatorDivideAssign.md)
- [`operator%`](../../docs/math/Integer/operatorModulo.md)
- [`operator%=`](../../docs/math/Integer/operatorModuloAssign.md)
- [`operator~`](../../docs/math/Integer/operatorBitwiseNot.md)
- [`operator&`](../../docs/math/Integer/operatorBitwiseAnd.md)
- [`operator&=`](../../docs/math/Integer/operatorBitwiseNotAssign.md)
- [`operator|`](../../docs/math/Integer/operatorBitwiseOr.md)
- [`operator|=`](../../docs/math/Integer/operatorBitwiseOrAssign.md)
- [`operator^`](../../docs/math/Integer/operatorBitwiseXor.md)
- [`operator^=`](../../docs/math/Integer/operatorBitwiseXorAssign.md)
- [`operator<<`](../../docs/math/Integer/operatorBitwiseShiftLeft.md)
- [`operator<<=`](../../docs/math/Integer/operatorBitwiseShiftLeftAssign.md)
- [`operator>>`](../../docs/math/Integer/operatorBitwiseShiftRight.md)
- [`operator>>=`](../../docs/math/Integer/operatorBitwiseShiftRightAssign.md)

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

	std::cout
		<< std::boolalpha
		<< (a == b)
		<< '\n';
}
```
Output:
```
true
```
