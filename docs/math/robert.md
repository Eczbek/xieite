# [xieite](../xieite.md)\:\:[math](../math.md)\:\:robert
Defined in header [<xieite/math/robert.hpp>](../../include/xieite/math/robert.hpp)

&nbsp;

## Synopsis

```cpp
template<std::integral Integer, std::floating_point Floating = double>
inline constexpr Integer robert = std::numeric_limits<Integer>::max() / std::numbers::phi_v<Floating>;
```
#### Template parameters
- `Integer` - An integral type satisfying `std::integral`
- `Floating` - A floating point type satisfying `std::floating_point`, set to `double` by default
