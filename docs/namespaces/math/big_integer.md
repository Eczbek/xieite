# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:BigInteger\<\> \{\}
Defined in header [<xieite/math/big_integer.hpp>](../../../include/xieite/math/big_integer.hpp)

&nbsp;

## Description
A structure for storing and operating on very large numbers. Multiplication, division, and stringification methods are currently significantly suboptimal.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::unsigned_integral Word_ = std::uint64_t>
struct BigInteger {
    using Word = Word_;

    template<std::integral Integral_ = int>
    constexpr BigInteger(Integral_ = 0) noexcept;

    template<typename OtherWord_>
    constexpr BigInteger(const xieite::math::BigInteger<OtherWord_>&) noexcept;

    template<std::ranges::range Range_>
    requires(std::same_as<std::ranges::range_value_t<Range_>, Word_>)
    constexpr BigInteger(Range_&&, bool = false) noexcept;

    constexpr BigInteger(std::string_view, xieite::math::SignedSize = 10, xieite::strings::NumberComponents = xieite::strings::NumberComponents()) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator=(Integral_) noexcept;

    template<std::integral Integral_>
    explicit constexpr operator Integral_() const noexcept;

    explicit constexpr operator bool() const noexcept;

    friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    friend constexpr bool operator==(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) const noexcept;

    template<std::integral Integral_>
    friend constexpr bool operator==(const xieite::math::BigInteger<Word_>&, Integral_) const noexcept;

    constexpr xieite::math::BigInteger<Word_> operator+() const noexcept;

    friend constexpr xieite::math::BigInteger<Word_> operator+(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr xieite::math::BigInteger<Word_> operator+(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator+=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator+=(Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator++() noexcept;

    constexpr xieite::math::BigInteger<Word_> operator++(int) noexcept;

    constexpr xieite::math::BigInteger<Word_> operator-() const noexcept;

    friend constexpr xieite::math::BigInteger<Word_> operator-(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr xieite::math::BigInteger<Word_> operator-(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator-=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator-=(Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator--() noexcept;

    constexpr xieite::math::BigInteger<Word_> operator--(int) noexcept;

    friend constexpr xieite::math::BigInteger<Word_> operator*(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&);

    template<std::integral Integral_>
    friend constexpr xieite::math::BigInteger<Word_> operator*(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator*=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator*=(Integral_) noexcept;

    friend constexpr std::optional<xieite::math::BigInteger<Word_>> operator/(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr std::optional<xieite::math::BigInteger<Word_>> operator/(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr std::optional<std::reference_wrapper<xieite::math::BigInteger<Word_>>> operator/=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr std::optional<std::reference_wrapper<xieite::math::BigInteger<Word_>>> operator/=(Integral_) noexcept;

    friend constexpr std::optional<xieite::math::BigInteger<Word_>> operator%(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr std::optional<xieite::math::BigInteger<Word_>> operator%(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr std::optional<std::reference_wrapper<xieite::math::BigInteger<Word_>>> operator%=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr std::optional<std::reference_wrapper<xieite::math::BigInteger<Word_>>> operator%=(Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_> operator~() const noexcept;

    friend constexpr xieite::math::BigInteger<Word_> operator&(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr xieite::math::BigInteger<Word_> operator&(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator&=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator&=(Integral_) noexcept;

    friend constexpr xieite::math::BigInteger<Word_> operator|(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr xieite::math::BigInteger<Word_> operator|(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator|=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator|=(Integral_) noexcept;

    friend constexpr xieite::math::BigInteger<Word_> operator^(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr xieite::math::BigInteger<Word_> operator^(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator^=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator^=(Integral_) noexcept;

    friend constexpr xieite::math::BigInteger<Word_> operator<<(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr xieite::math::BigInteger<Word_> operator<<(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator<<=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator<<=(Integral_) noexcept;

    friend constexpr xieite::math::BigInteger<Word_> operator>>(const xieite::math::BigInteger<Word_>&, const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    friend constexpr xieite::math::BigInteger<Word_> operator>>(const xieite::math::BigInteger<Word_>&, Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_>& operator>>=(const xieite::math::BigInteger<Word_>&) noexcept;

    template<std::integral Integral_>
    constexpr xieite::math::BigInteger<Word_>& operator>>=(Integral_) noexcept;

    constexpr xieite::math::BigInteger<Word_> absolute() const noexcept;

    constexpr std::optional<xieite::math::BigInteger<Word_>> power(const xieite::math::BigInteger<Word_>&) const noexcept;

    template<std::integral Integral_>
    constexpr std::optional<xieite::math::BigInteger<Word_>> power(Integral_) const noexcept;

    constexpr std::optional<xieite::math::BigInteger<Word_>> root(const xieite::math::BigInteger<Word_>&) const noexcept;

    template<std::integral Integral_>
    constexpr std::optional<xieite::math::BigInteger<Word_>> root(Integral_) const noexcept;

    constexpr std::optional<xieite::math::BigInteger<Word_>> logarithm(const xieite::math::BigInteger<Word_>&) const noexcept;

    template<std::integral Integral_>
    constexpr std::optional<xieite::math::BigInteger<Word_>> logarithm(Integral_) const noexcept;

    constexpr std::string string(xieite::math::SignedSize = 10, xieite::strings::NumberComponents = xieite::strings::NumberComponents()) const noexcept;
};
```
- Word
- [BigInteger\<\>\(\)](./structures/big_integer/1/operators/constructor.md)
- [operator=\<\>\(\)](./structures/big_integer/1/operators/assign.md)
- [operator typename\<\>\(\)](./structures/big_integer/1/operators/cast.md)
- [operator\<=\>\<\>\(\)](./structures/big_integer/1/operators/spaceship.md)
- [operator==\<\>\(\)](./structures/big_integer/1/operators/s/equal.md)
- [operator+\<\>\(\)](./structures/big_integer/1/operators/add.md)
- [operator+=\<\>\(\)](./structures/big_integer/1/operators/addAssign.md)
- [operator++\(\)](./structures/big_integer/1/operators/increment.md)
- [operator-\<\>\(\)](./structures/big_integer/1/operators/subtract.md)
- [operator-=\<\>\(\)](./structures/big_integer/1/operators/subtract_assign.md)
- [operator--\(\)](./structures/big_integer/1/operators/decrement.md)
- [operator*\<\>\(\)](./structures/big_integer/1/operators/multiply.md)
- [operator*=\<\>\(\)](./structures/big_integer/1/operators/multiply_assign.md)
- [operator/\<\>\(\)](./structures/big_integer/1/operators/divide.md)
- [operator/=\<\>\(\)](./structures/big_integer/1/operators/divide_assign.md)
- [operator%\<\>\(\)](./structures/big_integer/1/operators/modulo.md)
- [operator%=\<\>\(\)](./structures/big_integer/1/operators/modulo_assign.md)
- [operator~\(\)](./structures/big_integer/1/operators/bitwise_not.md)
- [operator&\<\>\(\)](./structures/big_integer/1/operators/bitwise_and.md)
- [operator&=\<\>\(\)](./structures/big_integer/1/operators/bitwise_and_assign.md)
- [operator|\<\>\(\)](./structures/big_integer/1/operators/bitwise_or.md)
- [operator|=\<\>\(\)](./structures/big_integer/1/operators/bitwise_or_assign.md)
- [operator^\<\>\(\)](./structures/big_integer/1/operators/bitwise_xor.md)
- [operator^=\<\>\(\)](./structures/big_integer/1/operators/bitwise_xor_assign.md)
- [operator\<\<\<\>\(\)](./structures/big_integer/1/operators/bitwise_shift_left.md)
- [operator\<\<=\<\>\(\)](./structures/big_integer/1/operators/bitwise_shift_left_assign.md)
- [operator\>\>\<\>\(\)](./structures/big_integer/1/operators/bitwise_shift_right.md)
- [operator\>\>=\<\>\(\)](./structures/big_integer/1/operators/bitwise_shift_right_assign.md)
- [absolute\(\)](./structures/big_integer/1/absolute.md)
- [power\<\>\(\)](./structures/big_integer/1/power.md)
- [root\<\>\(\)](./structures/big_integer/1/root.md)
- [logarithm\<\>\(\)](./structures/big_integer/1/logarithm.md)
- [string\(\)](./structures/big_integer/1/string.md)

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/math/big_integer.hpp"

int main() {
    std::println("{}", xieite::math::BigInteger(99).power(99).string());
}
```
Output:
```
369729637649726772657187905628805440595668764281741102430259972423552570455277523421410650010128232727940978889548326540119429996769494359451621570193644014418071060667659301384999779999159200499899
```
