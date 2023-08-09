# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsNoThrowConvertibleToAllOf
Defined in header [<xieite/traits/IsNoThrowConvertibleToAllOf.hpp>](../../include/xieite/traits/IsNoThrowConvertibleToAllOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsNoThrowConvertibleToAllOf
: std::bool_constant<xieite::concepts::NoThrowConvertibleToAllOf<Source, Targets...>> {};
```
