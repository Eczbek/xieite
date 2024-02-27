# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:SizedInteger
Defined in header [<xieite/math/sized_integer.hpp>](../../../include/xieite/math/sized_integer.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t bits, bool sign>
struct Integer {
    using Type = Word;

    template<std::integral OtherInteger = int>
    constexpr Integer(OtherInteger = 0);

    constexpr xieite::math::SizedInteger<bits, sign>& operator=(const xieite::math::SizedInteger<bits, sign>);

    template<std::integral OtherInteger>
    constexpr operator OtherInteger() const;

    template<std::size_t otherBits, bool otherSign>
    constexpr operator xieite::math::SizedInteger<otherBits, otherSign>() const;

    friend constexpr std::strong_ordering operator<=>(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    friend constexpr bool operator==(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>) const;

    constexpr xieite::math::SizedInteger<bits, sign> operator+() const;

    friend constexpr xieite::math::SizedInteger<bits, sign> operator+(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator+=(const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator++();

    constexpr xieite::math::SizedInteger<bits, sign> operator++(int);

    constexpr xieite::math::SizedInteger<bits, sign> operator-() const;

    friend constexpr xieite::math::SizedInteger<bits, sign> operator-(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator-=(const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator--();

    constexpr xieite::math::SizedInteger<bits, sign> operator--(int);

    friend constexpr xieite::math::SizedInteger<bits, sign> operator*(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator*=(const xieite::math::SizedInteger<bits, sign>);

    friend constexpr xieite::math::SizedInteger<bits, sign> operator/(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator/=(const xieite::math::SizedInteger<bits, sign>);

    friend constexpr xieite::math::SizedInteger<bits, sign> operator%(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator%=(const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign> operator~() const;

    friend constexpr xieite::math::SizedInteger<bits, sign> operator&(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator&=(const xieite::math::SizedInteger<bits, sign>);

    friend constexpr xieite::math::SizedInteger<bits, sign> operator|(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator|=(const xieite::math::SizedInteger<bits, sign>);

    friend constexpr xieite::math::SizedInteger<bits, sign> operator^(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator^=(const xieite::math::SizedInteger<bits, sign>);

    friend constexpr xieite::math::SizedInteger<bits, sign> operator<<(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator<<=(const xieite::math::SizedInteger<bits, sign>);

    friend constexpr xieite::math::SizedInteger<bits, sign> operator>>(const xieite::math::SizedInteger<bits, sign>, const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>& operator>>=(const xieite::math::SizedInteger<bits, sign>);

    constexpr xieite::math::SizedInteger<bits, sign>::Type data() const;
};
```
##### Member types
- [Type](./structures/integer/1/type.md)
##### Member functions
- [Integer](./structures/integer/1/operators/constructor.md)
- [operator=](./structures/integer/1/operators/assign.md)
- [operator typename](./structures/integer/1/operators/cast.md)
- [operator<=>](./structures/integer/1/operators/spaceship.md)
- [operator==](./structures/integer/1/operators/s/equal.md)
- [operator+](./structures/integer/1/operators/add.md)
- [operator+=](./structures/integer/1/operators/addAssign.md)
- [operator++](./structures/integer/1/operators/increment.md)
- [operator-](./structures/integer/1/operators/subtract.md)
- [operator-=](./structures/integer/1/operators/subtract_assign.md)
- [operator--](./structures/integer/1/operators/decrement.md)
- [operator*](./structures/integer/1/operators/multiply.md)
- [operator*=](./structures/integer/1/operators/multiply_assign.md)
- [operator/](./structures/integer/1/operators/divide.md)
- [operator/=](./structures/integer/1/operators/divide_assign.md)
- [operator%](./structures/integer/1/operators/modulo.md)
- [operator%=](./structures/integer/1/operators/modulo_assign.md)
- [operator~](./structures/integer/1/operators/bitwise_not.md)
- [operator&](./structures/integer/1/operators/bitwise_and.md)
- [operator&=](./structures/integer/1/operators/bitwise_and_assign.md)
- [operator|](./structures/integer/1/operators/bitwise_or.md)
- [operator|=](./structures/integer/1/operators/bitwise_or_assign.md)
- [operator^](./structures/integer/1/operators/bitwise_xor.md)
- [operator^=](./structures/integer/1/operators/bitwise_xor_assign.md)
- [operator<<](./structures/integer/1/operators/bitwise_shift_left.md)
- [operator<<=](./structures/integer/1/operators/bitwise_shift_left_assign.md)
- [operator>>](./structures/integer/1/operators/bitwise_shift_right.md)
- [operator>>=](./structures/integer/1/operators/bitwise_shift_right_assign.md)
- [data](./structures/integer/1/data.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/sized_integer.hpp"

int main() {
    xieite::math::SizedInteger<3, false> integer = 0;
    for (int i = 0; i < 10; ++i) {
        ++integer;
        std::cout << static_cast<int>(integer) << '\n';
    }
}
```
Output:
```
1
2
3
4
5
6
7
0
1
2
```
