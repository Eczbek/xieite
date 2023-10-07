# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNumeric
Defined in header [<xieite/traits/IsNumeric.hpp>](../../../include/xieite/traits/IsNumeric.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
struct IsNumeric
: std::bool_constant<xieite::concepts::Numeric<Type>> {};
```
