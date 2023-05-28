# [xieite](../../README.md)::[math](../math.md)::Integer
Defined in header [<xieite/math/Integer.hpp>](../../include/xieite/math/Integer.hpp)

<br/>

Allows creation of integer types of any bit size. All mathematical operators are defined

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

	constexpr xieite::math::ConditionalIntegerSign<xieite::math::MinimalIntegerSize<bits>, sign> data() const;

	friend constexpr std::ostream& operator<<(std::ostream&, xieite::math::Integer<bits, sign>);

	friend constexpr std::istream& operator>>(std::istream&, xieite::math::Integer<bits, sign>&);
};
```
### Template parameters
- `bits` - A `std::size_t` copy, how many bits the type can use
- `sign` - A `bool` copy, whether or not the type is signed
### Public members
<pre><code>Integer/
|- <a href="./Integer/constructor.md">Integer</a>
|- <a href="./Integer/operatorAssign.md">operator=</a>
|- <a href="./Integer/operatorCast.md">operator typename</a>
|- <a href="./Integer/operatorNot.md">operator!</a>
|- <a href="./Integer/operatorEquals.md">operator==</a>
|- <a href="./Integer/operatorSpaceship.md">operator<=></a>
|- <a href="./Integer/operatorAdd.md">operator+</a>
|- <a href="./Integer/operatorAddAssign.md">operator+=</a>
|- <a href="./Integer/operatorIncrement.md">operator++</a>
|- <a href="./Integer/operatorSubtract.md">operator-</a>
|- <a href="./Integer/operatorSubtractAssign.md">operator-=</a>
|- <a href="./Integer/operatorDecrement.md">operator--</a>
|- <a href="./Integer/operatorMultiply.md">operator*</a>
|- <a href="./Integer/operatorMultiplyAssign.md">operator*=</a>
|- <a href="./Integer/operatorDivide.md">operator/</a>
|- <a href="./Integer/operatorDivideAssign.md">operator/=</a>
|- <a href="./Integer/operatorModulo.md">operator%</a>
|- <a href="./Integer/operatorModuloAssign.md">operator%=</a>
|- <a href="./Integer/operatorBitwiseNot.md">operator~</a>
|- <a href="./Integer/operatorBitwiseAnd.md">operator&</a>
|- <a href="./Integer/operatorBitwiseNotAssign.md">operator&=</a>
|- <a href="./Integer/operatorBitwiseOr.md">operator|</a>
|- <a href="./Integer/operatorBitwiseOrAssign.md">operator|=</a>
|- <a href="./Integer/operatorBitwiseXor.md">operator^</a>
|- <a href="./Integer/operatorBitwiseXorAssign.md">operator^=</a>
|- <a href="./Integer/operatorBitwiseShiftLeft.md">operator<<</a>
|- <a href="./Integer/operatorBitwiseShiftLeftAssign.md">operator<<=</a>
|- <a href="./Integer/operatorBitwiseShiftRight.md">operator>></a>
|- <a href="./Integer/operatorBitwiseShiftRightAssign.md">operator>>=</a>
`- <a href="./Integer/data.md">data</a>
</code></pre>

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
