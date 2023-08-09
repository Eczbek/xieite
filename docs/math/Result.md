# [xieite](../xieite.md)\:\:[math](../math.md)\:\:Result
Defined in header [<xieite/math/Result.hpp>](../../include/xieite/math/Result.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
using Result = std::conditional_t<(std::same_as<Arithmetics, long double> || ...), long double, double>;
```
