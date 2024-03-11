# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Exponent
Defined in header [<xieite/math/exponent.hpp>](../../../include/xieite/math/exponent.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Numeric Number>
class Exponent {
private:
    struct Value;

public:
    constexpr Exponent(Number);

    template<xieite::concepts::Numeric OtherNumber>
    constexpr operator OtherNumber() const;

    constexpr xieite::math::Exponent<Number>::Value operator*() const;
};
```
##### Members
- [Value](./structures/exponent/1/value.md)
- [Exponent](./structures/exponent/1/operators/constructor.md)
- [operator typename](./structures/exponent/1/operators/cast.md)
- [operator*](./structures/exponent/1/operators/multiply.md)
