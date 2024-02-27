# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Exponent<Number>](../../../exponent.md)\:\:Value
Defined in header [<xieite/math/exponent.hpp>](../../../../../../include/xieite/math/exponent.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
struct Value {
    constexpr Value(Number);

    constexpr auto operator=(xieite::math::Exponent<Number>::Value) = delete;

    template<xieite::concepts::ArithmeticOtherNumber>
    friend constexpr std::common_type_t<Number, OtherNumber> operator*(OtherNumber, xieite::math::Exponent<Number>::Value);
};
```
##### Member functions
- [Value](./structures/value/1/operators/constructor.md)
- [operator*](./structures/value/1/operators/multiply.md)
