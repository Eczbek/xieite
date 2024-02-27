# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:roundDown
Defined in header [<xieite/math/round_down.hpp>](../../../include/xieite/math/round_down.hpp)

&nbsp;

## Description
Rounds a `value` to the nearest `step` toward `0`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
[[nodiscard]] constexpr std::common_type_t<Number1, Number2> roundDown(const Number1 value, const Number2 step = 1) noexcept;
```
