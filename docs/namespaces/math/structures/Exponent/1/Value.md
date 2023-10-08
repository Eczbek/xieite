# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Exponent\<Arithmetic\>](../../../Exponent.md)\:\:Value
Defined in header [<xieite/math/Exponent.hpp>](../../../../../../include/xieite/math/Exponent.hpp)

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
- [Value](./structures/Value/1/operators/constructor.md)
- [operator*](./structures/Value/1/operators/multiply.md)
