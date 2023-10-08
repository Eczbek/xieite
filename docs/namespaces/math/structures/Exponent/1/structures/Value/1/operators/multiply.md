# [xieite](../../../../../../../../../xieite.md)\:\:[math](../../../../../../../../../math.md)\:\:[Exponent\<Arithmetic\>](../../../../../../../Exponent.md)\:\:[Value](../../../../Value.md)\:\:operator*
Defined in header [<xieite/math/Exponent.hpp>](../../../../../../../../../../include/xieite/math/Exponent.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic OtherArithmetic>
[[nodiscard]] friend constexpr std::common_type_t<Arithmetic, OtherArithmetic> operator*(OtherArithmetic base, xieite::math::Exponent<Arithmetic>::Value exponent) noexcept;
```
