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

    constexpr BigInteger(std::string_view, int = 10, std::string_view = "0123456789abcdefghijklmnopqrstuvwxyz", char = '-');

    constexpr xieite::math::BigInteger<Datum>& operator=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator=(Integer);

    template<std::integral Integer>
    constexpr operator Integer() const;

    constexpr operator bool() const;

    constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    constexpr std::strong_ordering operator<=>(Integer) const;

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

    constexpr std::string string(int = 10, std::string_view = "0123456789abcdefghijklmnopqrstuvwxyz", char = '-') const;
};
```
##### Member functions
- [BigInteger](./BigInteger/constructor.md)
- [operator=](./BigInteger/operatorAssign.md)
- [operator typename](./BigInteger/operatorCast.md)
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
