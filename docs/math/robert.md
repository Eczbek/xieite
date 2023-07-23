# [xieite](../xieite.md)::[math](../math.md)::robert
Defined in header [<xieite/math/robert.hpp>](../../include/xieite/math/robert.hpp)

<br/><br/>

## Synopsis

```cpp
template<std::integral Integral>
inline constexpr Integral robert = std::numeric_limits<Integral>::max() / std::numbers::phi_v<double>;
```
### Template parameters
- `Integral` - An integral type satisfying `std::integral`
