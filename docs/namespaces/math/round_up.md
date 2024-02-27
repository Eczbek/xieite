# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundUp
Defined in header [<xieite/math/round_up.hpp>](../../../include/xieite/math/round_up.hpp)

&nbsp;

## Description
Rounds a `value` to the nearest `step` away from `0`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
[[nodiscard]] constexpr std::common_type_t<Number1, Number2> roundUp(const Number1 value, const Number2 step = 1) noexcept;
```
