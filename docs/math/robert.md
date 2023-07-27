# [xieite](../xieite.md)::[math](../math.md)::robert
Defined in header [<xieite/math/robert.hpp>](../../include/xieite/math/robert.hpp)

<br/><br/>

## Synopsis

```cpp
template<std::integral Integral, std::floating_point FloatingPoint = double>
inline constexpr Integral robert = std::numeric_limits<Integral>::max() / std::numbers::phi_v<FloatingPoint>;
```
### Template parameters
- `Integral` - An integral type satisfying `std::integral`
- `FloatingPoint` - A floating point type satisfying `std::floating_point`, set to `double` by default
