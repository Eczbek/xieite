# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsConvertibleToAnyOf
Defined in header [<xieite/traits/IsConvertibleToAnyOf.hpp>](../../include/xieite/traits/IsConvertibleToAnyOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsConvertibleToAnyOf
: std::bool_constant<xieite::concepts::ConvertibleToAnyOf<Source, Targets...>> {};
```
