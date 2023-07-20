# [xieite](../xieite.md)::[math](../math.md)::Result
Defined in header [<xieite/math/Result.hpp>](../../include/xieite/math/Result.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic... Numbers>
using Result = std::conditional_t<(std::same_as<Numbers, long double> || ...), long double, double>;
```
### Template parameters
- `Numbers` - Types satisfying `xieite::concepts::Arithmetic`
### Resulting type
- If any of `Numbers` is `long double`, then `long double`, otherwise `double`
