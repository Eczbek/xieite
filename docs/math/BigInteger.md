# [xieite](../xieite.md)::[math](../math.md)::BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../include/xieite/math/BigInteger.hpp)

<br/>

A class for storing and operating on very large numbers

<br/><br/>

## Synopsis

<br/>

```cpp
struct BigInteger {
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

	constexpr xieite::math::BigInteger logarithm(const xieite::math::BigInteger&) const;

	constexpr xieite::math::BigInteger logarithm(std::integral auto) const;

	constexpr const std::vector<bool>& data() const;

	constexpr std::string string() const;
};
```
### Public members
<pre><code>BigInteger/
|- <a href="./BigInteger/constructor.md">BigInteger</a>
|- <a href="./BigInteger/operatorAssign.md">operator=</a>
|- <a href="./BigInteger/operatorCast.md">operator typename</a>
|- <a href="./BigInteger/operatorNot.md">operator!</a>
|- <a href="./BigInteger/operatorEquals.md">operator==</a>
|- <a href="./BigInteger/operatorSpaceship.md">operator<=></a>
|- <a href="./BigInteger/operatorAdd.md">operator+</a>
|- <a href="./BigInteger/operatorAddAssign.md">operator+=</a>
|- <a href="./BigInteger/operatorIncrement.md">operator++</a>
|- <a href="./BigInteger/operatorSubtract.md">operator-</a>
|- <a href="./BigInteger/operatorSubtractAssign.md">operator-=</a>
|- <a href="./BigInteger/operatorDecrement.md">operator--</a>
|- <a href="./BigInteger/operatorMultiply.md">operator*</a>
|- <a href="./BigInteger/operatorMultiplyAssign.md">operator*=</a>
|- <a href="./BigInteger/operatorDivide.md">operator/</a>
|- <a href="./BigInteger/operatorDivideAssign.md">operator/=</a>
|- <a href="./BigInteger/operatorModulo.md">operator%</a>
|- <a href="./BigInteger/operatorModuloAssign.md">operator%=</a>
|- <a href="./BigInteger/operatorBitwiseNot.md">operator~</a>
|- <a href="./BigInteger/operatorBitwiseAnd.md">operator&</a>
|- <a href="./BigInteger/operatorBitwiseNotAssign.md">operator&=</a>
|- <a href="./BigInteger/operatorBitwiseOr.md">operator|</a>
|- <a href="./BigInteger/operatorBitwiseOrAssign.md">operator|=</a>
|- <a href="./BigInteger/operatorBitwiseXor.md">operator^</a>
|- <a href="./BigInteger/operatorBitwiseXorAssign.md">operator^=</a>
|- <a href="./BigInteger/operatorBitwiseShiftLeft.md">operator<<</a>
|- <a href="./BigInteger/operatorBitwiseShiftLeftAssign.md">operator<<=</a>
|- <a href="./BigInteger/operatorBitwiseShiftRight.md">operator>></a>
|- <a href="./BigInteger/operatorBitwiseShiftRightAssign.md">operator>>=</a>
|- <a href="./BigInteger/absolute.md">absolute</a>
|- <a href="./BigInteger/power.md">power</a>
|- <a href="./BigInteger/root.md">root</a>
|- <a href="./BigInteger/logarithm.md">logarithm</a>
|- <a href="./BigInteger/data.md">data</a>
`- <a href="./BigInteger/string.md">string</a>
</code></pre>

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
