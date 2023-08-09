# [xieite](../xieite.md)\:\:[math](../math.md)\:\:BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
A class for storing and operating on very large numbers.

&nbsp;

## Synopses
#### 1)
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
##### Member functions
- [BigInteger](./BigInteger/constructor.md)
- [operator=](./BigInteger/operatorAssign.md)
- [operator typename](./BigInteger/operatorCast.md)
- [operator!](./BigInteger/operatorNot.md)
- [operator==](./BigInteger/operatorEquals.md)
- [operator<=>](./BigInteger/operatorSpaceship.md)
- [operator+](./BigInteger/operatorAdd.md)
- [operator+=](./BigInteger/operatorAddAssign.md)
- [operator++](./BigInteger/operatorIncrement.md)
- [operator-](./BigInteger/operatorSubtract.md)
- [operator-=](./BigInteger/operatorSubtractAssign.md)
- [operator--](./BigInteger/operatorDecrement.md)
- [operator*](./BigInteger/operatorMultiply.md)
- [operator*=](./BigInteger/operatorMultiplyAssign.md)
- [operator/](./BigInteger/operatorDivide.md)
- [operator/=](./BigInteger/operatorDivideAssign.md)
- [operator%](./BigInteger/operatorModulo.md)
- [operator%=](./BigInteger/operatorModuloAssign.md)
- [operator~](./BigInteger/operatorBitwiseNot.md)
- [operator&](./BigInteger/operatorBitwiseAnd.md)
- [operator&=](./BigInteger/operatorBitwiseNotAssign.md)
- [operator|](./BigInteger/operatorBitwiseOr.md)
- [operator|=](./BigInteger/operatorBitwiseOrAssign.md)
- [operator^](./BigInteger/operatorBitwiseXor.md)
- [operator^=](./BigInteger/operatorBitwiseXorAssign.md)
- [operator<<](./BigInteger/operatorBitwiseShiftLeft.md)
- [operator<<=](./BigInteger/operatorBitwiseShiftLeftAssign.md)
- [operator>>](./BigInteger/operatorBitwiseShiftRight.md)
- [operator>>=](./BigInteger/operatorBitwiseShiftRightAssign.md)
- [absolute](./BigInteger/absolute.md)
- [power](./BigInteger/power.md)
- [root](./BigInteger/root.md)
- [logarithm](./BigInteger/logarithm.md)
- [data](./BigInteger/data.md)
- [string](./BigInteger/string.md)

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
