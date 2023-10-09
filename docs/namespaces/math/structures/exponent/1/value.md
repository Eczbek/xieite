# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Exponent\<Arithmetic\>](../../../exponent.md)\:\:Value
Defined in header [<xieite/math/exponent.hpp>](../../../../../../include/xieite/math/exponent.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
struct Value {
    constexpr Value(Arithmetic);

    constexpr auto operator=(xieite::math::Exponent<Arithmetic>::Value) = delete;

    template<xieite::concepts::Arithmetic OtherArithmetic>
    friend constexpr std::common_type_t<Arithmetic, OtherArithmetic> operator*(OtherArithmetic, xieite::math::Exponent<Arithmetic>::Value);
};
```
##### Member functions
- [Value](./structures/value/1/operators/constructor.md)
- [operator*](./structures/value/1/operators/multiply.md)
