# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Integer \{\}
Defined in header [<xieite/math/integer.hpp>](../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
A wrapper for a bit-field.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t bits, bool sign>
struct Integer {
    using Type = xieite::types::MaybeSigned<xieite::types::LeastInteger<bits>, sign>;

    template<std::integral OtherIntegral = int>
    constexpr Integer(OtherIntegral = 0) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator=(xieite::math::Integer<bits, sign>) noexcept;

    template<std::integral OtherIntegral>
    constexpr operator OtherIntegral() const noexcept;

    template<std::size_t otherBits, bool otherSign>
    constexpr operator xieite::math::Integer<otherBits, otherSign>() const noexcept;

    friend constexpr std::strong_ordering operator<=>(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    friend constexpr bool operator==(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign> operator+() const noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator+(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator+=(xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator++() noexcept;

    constexpr xieite::math::Integer<bits, sign> operator++(int) noexcept;

    constexpr xieite::math::Integer<bits, sign> operator-() const noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator-(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator-=(xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator--() noexcept;

    constexpr xieite::math::Integer<bits, sign> operator--(int) noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator*(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator*=(xieite::math::Integer<bits, sign>) noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator/(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator/=(xieite::math::Integer<bits, sign>) noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator%(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator%=(xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign> operator~() const noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator&(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator&=(xieite::math::Integer<bits, sign>) noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator|(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator|=(xieite::math::Integer<bits, sign>) noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator^(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator^=(xieite::math::Integer<bits, sign>) noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator<<(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator<<=(xieite::math::Integer<bits, sign>) noexcept;

    friend constexpr xieite::math::Integer<bits, sign> operator>>(xieite::math::Integer<bits, sign>, xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>& operator>>=(xieite::math::Integer<bits, sign>) noexcept;

    constexpr xieite::math::Integer<bits, sign>::Type data() const noexcept;
};
```
##### Members
- Type
- [Integral\(\)](./structures/integer/1/operators/constructor.md)
- [operator=\(\)](./structures/integer/1/operators/assign.md)
- [operator typename\(\)](./structures/integer/1/operators/cast.md)
- [operator<=>\(\)](./structures/integer/1/operators/spaceship.md)
- [operator==\(\)](./structures/integer/1/operators/s/equal.md)
- [operator+\(\)](./structures/integer/1/operators/add.md)
- [operator+=\(\)](./structures/integer/1/operators/addAssign.md)
- [operator++\(\)](./structures/integer/1/operators/increment.md)
- [operator-\(\)](./structures/integer/1/operators/subtract.md)
- [operator-=\(\)](./structures/integer/1/operators/subtract_assign.md)
- [operator--\(\)](./structures/integer/1/operators/decrement.md)
- [operator*\(\)](./structures/integer/1/operators/multiply.md)
- [operator*=\(\)](./structures/integer/1/operators/multiply_assign.md)
- [operator/\(\)](./structures/integer/1/operators/divide.md)
- [operator/=\(\)](./structures/integer/1/operators/divide_assign.md)
- [operator%\(\)](./structures/integer/1/operators/modulo.md)
- [operator%=\(\)](./structures/integer/1/operators/modulo_assign.md)
- [operator~\(\)](./structures/integer/1/operators/bitwise_not.md)
- [operator&\(\)](./structures/integer/1/operators/bitwise_and.md)
- [operator&=\(\)](./structures/integer/1/operators/bitwise_and_assign.md)
- [operator|\(\)](./structures/integer/1/operators/bitwise_or.md)
- [operator|=\(\)](./structures/integer/1/operators/bitwise_or_assign.md)
- [operator^\(\)](./structures/integer/1/operators/bitwise_xor.md)
- [operator^=\(\)](./structures/integer/1/operators/bitwise_xor_assign.md)
- [operator<<\(\)](./structures/integer/1/operators/bitwise_shift_left.md)
- [operator<<=\(\)](./structures/integer/1/operators/bitwise_shift_left_assign.md)
- [operator>>\(\)](./structures/integer/1/operators/bitwise_shift_right.md)
- [operator>>=\(\)](./structures/integer/1/operators/bitwise_shift_right_assign.md)
- [data\(\)](./structures/integer/1/data.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/integer.hpp"

int main() {
    xieite::math::Integer<3, false> integer = 0;
    for (int i = 0; i < 10; ++i) {
        ++integer;
        std::println("{}", static_cast<int>(integer)) noexcept;
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
