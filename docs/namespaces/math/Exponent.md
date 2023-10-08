# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Exponent
Defined in header [<xieite/math/Exponent.hpp>](../../../include/xieite/math/Exponent.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
class Exponent {
private:
    struct Value;

public:
    constexpr Exponent(Arithmetic);

    template<xieite::concepts::Arithmetic OtherArithmetic>
    constexpr operator OtherArithmetic() const;

    constexpr xieite::math::Exponent<Arithmetic>::Value operator*() const;
};
```
##### Member types
- [Value](./structures/Exponent/1/Value.md)
##### Member functions
- [Exponent](./structures/Exponent/1/operators/constructor.md)
- [operator typename](./structures/Exponent/1/operators/cast.md)
- [operator*](./structures/Exponent/1/operators/multiply.md)
