# [xieite](../xieite.md)\:\:[math](../math.md)\:\:BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../include/xieite/math/BigInteger.hpp)

&nbsp;

## Description
A class for storing and operating on very large numbers.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::unsigned_integral Datum = std::uint64_t>
struct BigInteger {
    template<std::integral Integer = int>
    constexpr BigInteger(Integer = 0);

    template<typename OtherDatum, typename OtherOperand>
    constexpr BigInteger(const xieite::math::BigInteger<OtherDatum, OtherOperand>&);

    template<std::ranges::range Range>
    requires(std::same_as<Datum, std::ranges::range_value_t<Range>>)
    constexpr BigInteger(const Range&, bool = false);

    constexpr BigInteger(std::string_view, const xieite::math::Base& = xieite::math::decimal);

    constexpr xieite::math::BigInteger<Datum>& operator=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator=(Integer);

    template<std::integral Integer>
    constexpr operator Integer() const;

    constexpr operator bool() const;

    constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    constexpr std::strong_ordering operator<=>(Integer) const;

    constexpr bool operator==(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    constexpr bool operator==(Integer) const;

    constexpr xieite::math::BigInteger<Datum> operator+() const;

    friend constexpr xieite::math::BigInteger<Datum> operator+(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator+(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator+=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator+=(Integer);

    constexpr xieite::math::BigInteger<Datum>& operator++();

    constexpr xieite::math::BigInteger<Datum> operator++(int);

    constexpr xieite::math::BigInteger<Datum> operator-() const;

    friend constexpr xieite::math::BigInteger<Datum> operator-(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator-(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator-=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator-=(Integer);

    constexpr xieite::math::BigInteger<Datum>& operator--();

    constexpr xieite::math::BigInteger<Datum> operator--(int);

    friend constexpr xieite::math::BigInteger<Datum> operator*(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator*(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator*=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator*=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator/(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator/(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator/=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator/=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator%(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator%(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator%=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator%=(Integer);

    constexpr xieite::math::BigInteger<Datum> operator~() const;

    friend constexpr xieite::math::BigInteger<Datum> operator&(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator&(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator&=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator&=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator|(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator|(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator|=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator|=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator^(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator^(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator^=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator^=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator<<(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator<<(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator<<=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator<<=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator>>(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator>>(Integer) const;

    constexpr xieite::math::BigInteger<Datum>& operator>>=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator>>=(Integer);

    constexpr xieite::math::BigInteger<Datum> absolute() const;

    constexpr xieite::math::BigInteger<Datum> power(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum> power(Integer) const;

    constexpr xieite::math::BigInteger<Datum> root(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum> root(Integer) const;

    constexpr xieite::math::BigInteger<Datum> logarithm(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum> logarithm(Integer) const;

    constexpr std::string string(const xieite::math::Base& = xieite::math::decimal) const;
};
```
##### Member functions
- [BigInteger](./BigInteger/1/constructor.md)
- [operator=](./BigInteger/1/operatorAssign.md)
- [operator typename](./BigInteger/1/operatorCast.md)
- [operator<=>](./BigInteger/1/operatorSpaceship.md)
- [operator==](./BigInteger/1/operatorEqual.md)
- [operator+](./BigInteger/1/operatorAdd.md)
- [operator+=](./BigInteger/1/operatorAddAssign.md)
- [operator++](./BigInteger/1/operatorIncrement.md)
- [operator-](./BigInteger/1/operatorSubtract.md)
- [operator-=](./BigInteger/1/operatorSubtractAssign.md)
- [operator--](./BigInteger/1/operatorDecrement.md)
- [operator*](./BigInteger/1/operatorMultiply.md)
- [operator*=](./BigInteger/1/operatorMultiplyAssign.md)
- [operator/](./BigInteger/1/operatorDivide.md)
- [operator/=](./BigInteger/1/operatorDivideAssign.md)
- [operator%](./BigInteger/1/operatorModulo.md)
- [operator%=](./BigInteger/1/operatorModuloAssign.md)
- [operator~](./BigInteger/1/operatorBitwiseNot.md)
- [operator&](./BigInteger/1/operatorBitwiseAnd.md)
- [operator&=](./BigInteger/1/operatorBitwiseNotAssign.md)
- [operator|](./BigInteger/1/operatorBitwiseOr.md)
- [operator|=](./BigInteger/1/operatorBitwiseOrAssign.md)
- [operator^](./BigInteger/1/operatorBitwiseXor.md)
- [operator^=](./BigInteger/1/operatorBitwiseXorAssign.md)
- [operator<<](./BigInteger/1/operatorBitwiseShiftLeft.md)
- [operator<<=](./BigInteger/1/operatorBitwiseShiftLeftAssign.md)
- [operator>>](./BigInteger/1/operatorBitwiseShiftRight.md)
- [operator>>=](./BigInteger/1/operatorBitwiseShiftRightAssign.md)
- [absolute](./BigInteger/1/absolute.md)
- [power](./BigInteger/1/power.md)
- [root](./BigInteger/1/root.md)
- [logarithm](./BigInteger/1/logarithm.md)
- [string](./BigInteger/1/string.md)

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
