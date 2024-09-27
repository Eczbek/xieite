# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Number\<\> \{\}
Defined in fragment [xieite:math.Number](../../../src/math/number.cpp)

&nbsp;

## Description
A wrapper for an integer or floating point type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
struct Number
: std::type_identity<Arithmetic> {
    Arithmetic value;

    explicit(false) constexpr Number(Arithmetic = 0) noexcept;

    explicit constexpr operator Arithmetic() const noexcept;

    template<xieite::concepts::Arithmetic OtherArithmetic>
    explicit constexpr operator xieite::math::Number<OtherArithmetic>() const noexcept;

    friend constexpr std::strong_ordering operator<=>(Number, Number) noexcept;

    friend bool operator==(Number, Number) = default;

    constexpr Number operator+() const noexcept;

    friend constexpr Number operator+(Number, Number) noexcept;

    constexpr Number& operator+=(Number) noexcept;

    constexpr Number& operator++() noexcept;

    constexpr Number operator++(int) noexcept;

    constexpr Number operator-() const noexcept;

    friend constexpr Number operator-(Number, Number) noexcept;

    constexpr Number& operator-=(Number) noexcept;

    constexpr Number& operator--() noexcept;

    constexpr Number operator--(int) noexcept;

    friend constexpr Number operator*(Number, Number) noexcept;

    constexpr Number& operator*=(Number) noexcept;

    friend constexpr Number operator/(Number, Number) noexcept;

    constexpr Number& operator/=(Number) noexcept;

    friend constexpr Number operator%(Number, Number) noexcept;

    constexpr Number& operator%=(Number) noexcept;

    constexpr Number operator~() const noexcept;

    friend constexpr Number operator&(Number, Number) noexcept;

    constexpr Number& operator&=(Number) noexcept;

    friend constexpr Number operator|(Number, Number) noexcept;

    constexpr Number& operator|=(Number) noexcept;

    friend constexpr Number operator^(Number, Number) noexcept;

    constexpr Number& operator^=(Number) noexcept;

    friend constexpr Number operator<<(Number, Number) noexcept;

    constexpr Number& operator<<=(Number) noexcept;

    friend constexpr Number operator>>(Number, Number) noexcept;

    constexpr Number& operator>>=(Number) noexcept;
};
```
- value
- [Number\<\>\(\)](./structures/number/1/operators/constructor.md)
- [operator typename\<\>\(\)](./structures/number/1/operators/cast.md)
- [operator<=>\(\)](./structures/number/1/operators/spaceship.md)
- [operator+\(\)](./structures/number/1/operators/add.md)
- [operator+=\(\)](./structures/number/1/operators/addAssign.md)
- [operator++\(\)](./structures/number/1/operators/increment.md)
- [operator-\(\)](./structures/number/1/operators/subtract.md)
- [operator-=\(\)](./structures/number/1/operators/subtract_assign.md)
- [operator--\(\)](./structures/number/1/operators/decrement.md)
- [operator\*\(\)](./structures/number/1/operators/multiply.md)
- [operator\*=\(\)](./structures/number/1/operators/multiply_assign.md)
- [operator/\(\)](./structures/number/1/operators/divide.md)
- [operator/=\(\)](./structures/number/1/operators/divide_assign.md)
- [operator%\(\)](./structures/number/1/operators/modulo.md)
- [operator%=\(\)](./structures/number/1/operators/modulo_assign.md)
- [operator~\(\)](./structures/number/1/operators/bitwise_not.md)
- [operator&\(\)](./structures/number/1/operators/bitwise_and.md)
- [operator&=\(\)](./structures/number/1/operators/bitwise_and_assign.md)
- [operator|\(\)](./structures/number/1/operators/bitwise_or.md)
- [operator|=\(\)](./structures/number/1/operators/bitwise_or_assign.md)
- [operator^\(\)](./structures/number/1/operators/bitwise_xor.md)
- [operator^=\(\)](./structures/number/1/operators/bitwise_xor_assign.md)
- [operator<<\(\)](./structures/number/1/operators/bitwise_shift_left.md)
- [operator<<=\(\)](./structures/number/1/operators/bitwise_shift_left_assign.md)
- [operator>>\(\)](./structures/number/1/operators/bitwise_shift_right.md)
- [operator>>=\(\)](./structures/number/1/operators/bitwise_shift_right_assign.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

struct Foo
: xieite::math::Number<int> {
    void test() {
        std::println("{}", this->value);
    }
};

int main() {
    Foo foo = 7;
    foo++;
    foo.test();
}
```
Output:
```
8
```
