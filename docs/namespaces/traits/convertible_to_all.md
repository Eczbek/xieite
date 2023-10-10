# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:ConvertibleToAll
Defined in header [<xieite/traits/convertible_to_all.hpp>](../../../include/xieite/traits/convertible_to_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct ConvertibleToAll
: std::bool_constant<xieite::concepts::ConvertibleToAll<Source, Targets...>> {};
```
