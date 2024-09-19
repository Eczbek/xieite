# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Exponent<Arithmetic>](../../../exponent.md)\:\:Intermediate \{\}
Defined in fragment [xieite:math.Exponent](../../../../../../src/math/exponent.cpp)

&nbsp;

## Description
An intermediate state for an exponent thingamabob.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Intermediate
: xieite::containers::MaybeCopyAssignable<false>, xieite::containers::MaybeMoveAssignable<false> {
    constexpr Intermediate(Arithmetic) noexcept;

    template<xieite::concepts::Arithmetic OtherArithmetic>
    friend constexpr std::common_type_t<Arithmetic, OtherArithmetic> operator*(OtherArithmetic, xieite::math::Exponent<Arithmetic>::Intermediate) noexcept;
};
```
- [Intermediate\(\)](./structures/intermediate/1/operators/constructor.md)
- [operator\*\(\)](./structures/intermediate/1/operators/multiply.md)

&nbsp;

## [Example](./operators/multiply.md#Example)
