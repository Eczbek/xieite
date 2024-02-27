# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[SizedInteger<bits, sign>](../../../../integer.md)\:\:operator typename
Defined in header [<xieite/math/sized_integer.hpp>](../../../../../../../include/xieite/math/sized_integer.hpp)

&nbsp;

## Description
Casts a `xieite::math::Integer` to any other integer type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral OtherInteger>
[[nodiscard]] constexpr operator OtherInteger() const noexcept;
```
