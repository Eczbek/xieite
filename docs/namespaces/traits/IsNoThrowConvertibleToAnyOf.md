# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNoThrowConvertibleToAnyOf
Defined in header [<xieite/traits/IsNoThrowConvertibleToAnyOf.hpp>](../../../include/xieite/traits/IsNoThrowConvertibleToAnyOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToAnyOf
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAnyOf<Source, Targets...>> {};
```
