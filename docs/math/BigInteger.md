# [xieite](../xieite.md)\:\:[math](../math.md)\:\:BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
A class for storing and operating on very large numbers

&nbsp;

## Synopsis
```cpp
struct BigInteger {
    template<std::integral Integer = int>
    constexpr BigInteger(Integer = 0);

    constexpr BigInteger(const xieite::math::BigInteger&);

    template<xieite::concepts::RangeOf<bool> BooleanRange>
    constexpr BigInteger(const BooleanRange&, bool = false);

    constexpr BigInteger(std::string_view);

    constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator=(Integer);

    template<xieite::concepts::Arithmetic Arithmetic>
    constexpr operator Arithmetic() const;

    constexpr operator bool() const;

    constexpr bool operator==(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr bool operator==(Integer) const;

    constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr std::strong_ordering operator<=>(Integer) const;

    constexpr xieite::math::BigInteger operator+() const;

    constexpr xieite::math::BigInteger operator+(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator+(Integer) const;

    constexpr xieite::math::BigInteger& operator+=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator+=(Integer);

    constexpr xieite::math::BigInteger& operator++();

    constexpr xieite::math::BigInteger operator++(int);

    constexpr xieite::math::BigInteger operator-() const;

    constexpr xieite::math::BigInteger operator-(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator-(Integer) const;

    constexpr xieite::math::BigInteger& operator-=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator-=(Integer);

    constexpr xieite::math::BigInteger& operator--();

    constexpr xieite::math::BigInteger operator--(int);

    constexpr xieite::math::BigInteger operator*(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator*(Integer) const;

    constexpr xieite::math::BigInteger& operator*=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator*=(Integer);

    constexpr xieite::math::BigInteger operator/(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator/(Integer) const;

    constexpr xieite::math::BigInteger& operator/=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator/=(Integer);

    constexpr xieite::math::BigInteger operator%(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator%(Integer) const;

    constexpr xieite::math::BigInteger& operator%=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator%=(Integer);

    constexpr xieite::math::BigInteger operator~() const;

    constexpr xieite::math::BigInteger operator&(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator&(Integer) const;

    constexpr xieite::math::BigInteger& operator&=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator&=(Integer);

    constexpr xieite::math::BigInteger operator|(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator|(Integer) const;

    constexpr xieite::math::BigInteger& operator|=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator|=(Integer);

    constexpr xieite::math::BigInteger operator^(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator^(Integer) const;

    constexpr xieite::math::BigInteger& operator^=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator^=(Integer);

    constexpr xieite::math::BigInteger operator<<(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator<<(Integer) const;

    constexpr xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator<<=(Integer);

    constexpr xieite::math::BigInteger operator>>(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger operator>>(Integer) const;

    constexpr xieite::math::BigInteger& operator>>=(const xieite::math::BigInteger&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger& operator>>=(Integer);

    constexpr xieite::math::BigInteger absolute() const;

    constexpr xieite::math::BigInteger power(xieite::math::BigInteger) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger power(Integer) const;

    constexpr xieite::math::BigInteger root(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger root(Integer) const;

    constexpr xieite::math::BigInteger logarithm(const xieite::math::BigInteger&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger logarithm(Integer) const;

    constexpr const std::vector<bool>& data() const;

    constexpr std::string string() const;
};
```
#### Public members
## Contents
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

&nbsp;

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
