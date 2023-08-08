# [xieite](../xieite.md)\:\:[math](../math.md)\:\:Result
Defined in header [<xieite/math/Result.hpp>](../../include/xieite/math/Result.hpp)

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic... Arithmetics>
using Result = std::conditional_t<(std::same_as<Arithmetics, long double> || ...), long double, double>;
```
#### Template parameters
- `Arithmetics` - Types satisfying `xieite::concepts::Arithmetic`
#### Resulting type
- If any of `Arithmetics` is `long double`, then `long double`, otherwise `double`
