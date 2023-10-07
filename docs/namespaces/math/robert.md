# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:robert
Defined in header [<xieite/math/robert.hpp>](../../../include/xieite/math/robert.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral Integer, std::floating_point FloatingPoint = double>
inline constexpr Integer robert = std::numeric_limits<Integer>::max() / std::numbers::phi_v<FloatingPoint>;
```
