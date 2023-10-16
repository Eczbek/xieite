# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:ceiling
Defined in header [<xieite/math/ceiling.hpp>](../../../include/xieite/math/ceiling.hpp)

&nbsp;

## Description
Rounds a `value` up to the next multiple of `step`.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
[[nodiscard]] constexpr std::common_type_t<Number1, Number2> ceiling(const Number1 value, const Number2 step = 1) noexcept;
```
