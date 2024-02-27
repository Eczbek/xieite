# [xieite](../../../../../../../../../xieite.md)\:\:[math](../../../../../../../../../math.md)\:\:[Exponent<Number>](../../../../../../../exponent.md)\:\:[Value](../../../../value.md)\:\:operator*
Defined in header [<xieite/math/exponent.hpp>](../../../../../../../../../../include/xieite/math/exponent.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Number OtherNumber>
[[nodiscard]] friend constexpr std::common_type_t<Number, OtherNumber> operator*(OtherNumber base, xieite::math::Exponent<Number>::Value exponent) noexcept;
```
