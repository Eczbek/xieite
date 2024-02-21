# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:floor
Defined in header [<xieite/math/floor.hpp"](../../../include/xieite/math/floor.hpp)

&nbsp;

## Description
Rounds a `value` down to the last multiple of `step`.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
[[nodiscard]] constexpr std::common_type_t<Number1, Number2> floor(const Number1 value, const Number2 step = 1) noexcept;
```
