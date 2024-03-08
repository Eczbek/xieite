# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:BigInteger
Defined in header [<xieite/math/big_integer.hpp>](../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
A class for storing and operating on very large numbers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::unsigned_integral Word = std::uint64_t>
struct BigInteger {
    using Type = Word;

    template<std::integral Integer = int>
    constexpr BigInteger(Integer = 0);

    template<typename OtherWord, typename OtherOperand>
    constexpr BigInteger(const xieite::math::BigInteger<OtherWord, OtherOperand>&);

    template<std::ranges::range Range>
    requires(std::same_as<std::ranges::range_value_t<Range>, Word>)
    constexpr BigInteger(const Range&, bool = false);

    constexpr BigInteger(std::string_view, xieite::math::SignedSize = 10, const xieite::strings::IntegerComponents& = xieite::strings::IntegerComponents());

    constexpr xieite::math::BigInteger<Word>& operator=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator=(Integer);

    template<std::integral Integer>
    constexpr operator Integer() const;

    constexpr operator bool() const;

    friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word>&, Integer);

    friend constexpr bool operator==(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&) const;

    template<std::integral Integer>
    friend constexpr bool operator==(const xieite::math::BigInteger<Word>&, Integer) const;

    constexpr xieite::math::BigInteger<Word> operator+() const;

    friend constexpr xieite::math::BigInteger<Word> operator+(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator+(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator+=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator+=(Integer);

    constexpr xieite::math::BigInteger<Word>& operator++();

    constexpr xieite::math::BigInteger<Word> operator++(int);

    constexpr xieite::math::BigInteger<Word> operator-() const;

    friend constexpr xieite::math::BigInteger<Word> operator-(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator-(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator-=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator-=(Integer);

    constexpr xieite::math::BigInteger<Word>& operator--();

    constexpr xieite::math::BigInteger<Word> operator--(int);

    friend constexpr xieite::math::BigInteger<Word> operator*(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator*(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator*=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator*=(Integer);

    friend constexpr xieite::math::BigInteger<Word> operator/(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator/(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator/=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator/=(Integer);

    friend constexpr xieite::math::BigInteger<Word> operator%(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator%(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator%=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator%=(Integer);

    constexpr xieite::math::BigInteger<Word> operator~() const;

    friend constexpr xieite::math::BigInteger<Word> operator&(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator&(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator&=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator&=(Integer);

    friend constexpr xieite::math::BigInteger<Word> operator|(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator|(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator|=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator|=(Integer);

    friend constexpr xieite::math::BigInteger<Word> operator^(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator^(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator^=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator^=(Integer);

    friend constexpr xieite::math::BigInteger<Word> operator<<(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator<<(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator<<=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator<<=(Integer);

    friend constexpr xieite::math::BigInteger<Word> operator>>(const xieite::math::BigInteger<Word>&, const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    friend constexpr xieite::math::BigInteger<Word> operator>>(const xieite::math::BigInteger<Word>&, Integer);

    constexpr xieite::math::BigInteger<Word>& operator>>=(const xieite::math::BigInteger<Word>&);

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word>& operator>>=(Integer);

    constexpr xieite::math::BigInteger<Word> absolute() const;

    constexpr xieite::math::BigInteger<Word> power(const xieite::math::BigInteger<Word>&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word> power(Integer) const;

    constexpr xieite::math::BigInteger<Word> root(const xieite::math::BigInteger<Word>&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word> root(Integer) const;

    constexpr xieite::math::BigInteger<Word> logarithm(const xieite::math::BigInteger<Word>&) const;

    template<std::integral Integer>
    constexpr xieite::math::BigInteger<Word> logarithm(Integer) const;

    constexpr std::string string(xieite::math::SignedSize = 10, const xieite::strings::IntegerComponents& = xieite::strings::IntegerComponents()) const;
};
```
##### Member types
- [Type](./structures/big_integer/1/type.md)
##### Member functions
- [BigInteger](./structures/big_integer/1/operators/constructor.md)
- [operator=](./structures/big_integer/1/operators/assign.md)
- [operator typename](./structures/big_integer/1/operators/cast.md)
- [operator<=>](./structures/big_integer/1/operators/spaceship.md)
- [operator==](./structures/big_integer/1/operators/s/equal.md)
- [operator+](./structures/big_integer/1/operators/add.md)
- [operator+=](./structures/big_integer/1/operators/addAssign.md)
- [operator++](./structures/big_integer/1/operators/increment.md)
- [operator-](./structures/big_integer/1/operators/subtract.md)
- [operator-=](./structures/big_integer/1/operators/subtract_assign.md)
- [operator--](./structures/big_integer/1/operators/decrement.md)
- [operator*](./structures/big_integer/1/operators/multiply.md)
- [operator*=](./structures/big_integer/1/operators/multiply_assign.md)
- [operator/](./structures/big_integer/1/operators/divide.md)
- [operator/=](./structures/big_integer/1/operators/divide_assign.md)
- [operator%](./structures/big_integer/1/operators/modulo.md)
- [operator%=](./structures/big_integer/1/operators/modulo_assign.md)
- [operator~](./structures/big_integer/1/operators/bitwise_not.md)
- [operator&](./structures/big_integer/1/operators/bitwise_and.md)
- [operator&=](./structures/big_integer/1/operators/bitwise_and_assign.md)
- [operator|](./structures/big_integer/1/operators/bitwise_or.md)
- [operator|=](./structures/big_integer/1/operators/bitwise_or_assign.md)
- [operator^](./structures/big_integer/1/operators/bitwise_xor.md)
- [operator^=](./structures/big_integer/1/operators/bitwise_xor_assign.md)
- [operator<<](./structures/big_integer/1/operators/bitwise_shift_left.md)
- [operator<<=](./structures/big_integer/1/operators/bitwise_shift_left_assign.md)
- [operator>>](./structures/big_integer/1/operators/bitwise_shift_right.md)
- [operator>>=](./structures/big_integer/1/operators/bitwise_shift_right_assign.md)
- [absolute](./structures/big_integer/1/absolute.md)
- [power](./structures/big_integer/1/power.md)
- [root](./structures/big_integer/1/root.md)
- [logarithm](./structures/big_integer/1/logarithm.md)
- [string](./structures/big_integer/1/string.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/big_integer.hpp"

int main() {
    std::cout << xieite::math::BigInteger(99).power(99).string() << '\n';
}
```
Output:
```
369729637649726772657187905628805440595668764281741102430259972423552570455277523421410650010128232727940978889548326540119429996769494359451621570193644014418071060667659301384999779999159200499899
```
