# [xieite](../../xieite.md)\:\:[units](../../units.md)\:\:convert
Defined in header [<xieite/units/convert.hpp>](../../../include/xieite/units/convert.hpp)

&nbsp;

## Description
Converts one unit type to another.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Ratio Source, xieite::concepts::Ratio Target, xieite::concepts::Numeric Number>
[[nodiscard]] constexpr xieite::math::Result<Number> convert(const Number value) noexcept;
```
