# [xieite](../../../../../../../../../xieite.md)\:\:[math](../../../../../../../../../math.md)\:\:[Exponent\<Arithmetic\>](../../../../../../../exponent.md)\:\:[Value](../../../../value.md)\:\:operator*
Defined in header [<xieite/math/exponent.hpp>](../../../../../../../../../../include/xieite/math/exponent.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic OtherArithmetic>
[[nodiscard]] friend constexpr std::common_type_t<Arithmetic, OtherArithmetic> operator*(OtherArithmetic base, xieite::math::Exponent<Arithmetic>::Value exponent) noexcept;
```
