# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:ConvertibleToNotAll
Defined in header [<xieite/traits/convertible_to_not_all.hpp>](../../../include/xieite/traits/convertible_to_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct ConvertibleToNotAll
: std::bool_constant<xieite::concepts::ConvertibleToNotAll<Source, Targets...>> {};
```
