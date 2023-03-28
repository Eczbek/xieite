# xieite::math::robert
Defined in header `<xieite/math/robert.hpp>`

<br/>

This excellently named constant exists for many noble purposes.

<br/><br/>

## Declarations
```cpp
template<std::integral Integral>
constexpr Integral robert = std::numeric_limits<Integral>::max() / std::numbers::phi_v<long double>;
```
