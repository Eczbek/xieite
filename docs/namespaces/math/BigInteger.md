# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:BigInteger
Defined in header [<xieite/math/BigInteger.hpp>](../../../include/xieite/math/BigInteger.hpp)

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

    constexpr BigInteger(std::string_view, int = 10, std::string_view = "0123456789abcdefghijklmnopqrstuvwxyz", char = '-', bool = false);

    constexpr xieite::math::BigInteger<Datum>& operator=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator=(Integer);

    template<std::integral Integer>
    constexpr operator Integer() const;

    constexpr operator bool() const;

    friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Datum>&, Integer);

    friend constexpr bool operator==(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&) const;

    template<std::integral Integer>
    friend constexpr bool operator==(const xieite::math::BigInteger<Datum>&, Integer) const;

    constexpr xieite::math::BigInteger<Datum> operator+() const;

    friend constexpr xieite::math::BigInteger<Datum> operator+(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator+(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator+=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator+=(Integer);

    constexpr xieite::math::BigInteger<Datum>& operator++();

    constexpr xieite::math::BigInteger<Datum> operator++(int);

    constexpr xieite::math::BigInteger<Datum> operator-() const;

    friend constexpr xieite::math::BigInteger<Datum> operator-(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator-(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator-=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator-=(Integer);

    constexpr xieite::math::BigInteger<Datum>& operator--();

    constexpr xieite::math::BigInteger<Datum> operator--(int);

    friend constexpr xieite::math::BigInteger<Datum> operator*(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator*(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator*=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator*=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator/(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator/(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator/=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator/=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator%(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator%(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator%=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator%=(Integer);

    constexpr xieite::math::BigInteger<Datum> operator~() const;

    friend constexpr xieite::math::BigInteger<Datum> operator&(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator&(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator&=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator&=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator|(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator|(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator|=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator|=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator^(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator^(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator^=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator^=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator<<(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator<<(const xieite::math::BigInteger<Datum>&, Integer);

    constexpr xieite::math::BigInteger<Datum>& operator<<=(const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Datum>& operator<<=(Integer);

    friend constexpr xieite::math::BigInteger<Datum> operator>>(const xieite::math::BigInteger<Datum>&, const xieite::math::BigInteger<Datum>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Datum> operator>>(const xieite::math::BigInteger<Datum>&, Integer);

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

    constexpr std::string string(int = 10, std::string_view = "0123456789abcdefghijklmnopqrstuvwxyz", char = '-', bool = false) const;
};
```
##### Member functions
- [BigInteger](./structures/BigInteger/1/operators/constructor.md)
- [operator=](./structures/BigInteger/1/operators/assign.md)
- [operator typename](./structures/BigInteger/1/operators/cast.md)
- [operator<=>](./structures/BigInteger/1/operators/spaceship.md)
- [operator==](./structures/BigInteger/1/operators/s/equal.md)
- [operator+](./structures/BigInteger/1/operators/add.md)
- [operator+=](./structures/BigInteger/1/operators/addAssign.md)
- [operator++](./structures/BigInteger/1/operators/increment.md)
- [operator-](./structures/BigInteger/1/operators/subtract.md)
- [operator-=](./structures/BigInteger/1/operators/subtractAssign.md)
- [operator--](./structures/BigInteger/1/operators/decrement.md)
- [operator*](./structures/BigInteger/1/operators/multiply.md)
- [operator*=](./structures/BigInteger/1/operators/multiplyAssign.md)
- [operator/](./structures/BigInteger/1/operators/divide.md)
- [operator/=](./structures/BigInteger/1/operators/divideAssign.md)
- [operator%](./structures/BigInteger/1/operators/modulo.md)
- [operator%=](./structures/BigInteger/1/operators/moduloAssign.md)
- [operator~](./structures/BigInteger/1/operators/bitwiseNot.md)
- [operator&](./structures/BigInteger/1/operators/bitwiseAnd.md)
- [operator&=](./structures/BigInteger/1/operators/bitwiseNotAssign.md)
- [operator|](./structures/BigInteger/1/operators/bitwiseOr.md)
- [operator|=](./structures/BigInteger/1/operators/bitwiseOrAssign.md)
- [operator^](./structures/BigInteger/1/operators/bitwiseXor.md)
- [operator^=](./structures/BigInteger/1/operators/bitwiseXorAssign.md)
- [operator<<](./structures/BigInteger/1/operators/bitwiseShiftLeft.md)
- [operator<<=](./structures/BigInteger/1/operators/bitwiseShiftLeftAssign.md)
- [operator>>](./structures/BigInteger/1/operators/bitwiseShiftRight.md)
- [operator>>=](./structures/BigInteger/1/operators/bitwiseShiftRightAssign.md)
- [absolute](./structures/BigInteger/1/absolute.md)
- [power](./structures/BigInteger/1/power.md)
- [root](./structures/BigInteger/1/root.md)
- [logarithm](./structures/BigInteger/1/logarithm.md)
- [string](./structures/BigInteger/1/string.md)

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