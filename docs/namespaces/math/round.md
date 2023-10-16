# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:round
Defined in header [<xieite/math/round.hpp>](../../../include/xieite/math/round.hpp)

&nbsp;

## Description
Rounds a `value` to the nearest `step`.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
[[nodiscard]] constexpr std::common_type_t<Number1, Number2> round(const Number1 value, const Number2 step = 1) noexcept;
```
