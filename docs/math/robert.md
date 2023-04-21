# `xieite::math::robert`
Defined in header [`<xieite/math/robert.hpp>`](../../include/xieite/math/robert.hpp)

<br/>

This excellently named constant exists for many noble purposes.

<br/><br/>

## Synopsis

```cpp
template<std::integral Integral>
constexpr Integral robert = std::numeric_limits<Integral>::max() / std::numbers::phi_v<long double>;
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`
