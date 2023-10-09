# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNumeric
Defined in header [<xieite/traits/is_numeric.hpp>](../../../include/xieite/traits/is_numeric.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsNumeric
: std::bool_constant<xieite::concepts::Numeric<Type>> {};
```
