# [xieite](../../../../../xieite.md)\:\:[math](../../../../../math.md)\:\:[Integer<bits, sign>](../../../../integer.md)\:\:operator typename
Defined in header [<xieite/math/integer.hpp>](../../../../../../../include/xieite/math/integer.hpp)

&nbsp;

## Description
Casts a `xieite::math::Integer` to any other integer type.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral OtherInteger>
[[nodiscard]] constexpr operator OtherInteger() const noexcept;
```
