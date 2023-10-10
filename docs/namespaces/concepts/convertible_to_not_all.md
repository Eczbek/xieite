# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToNotAll
Defined in header [<xieite/concepts/convertible_to_not_all.hpp>](../../../include/xieite/concepts/convertible_to_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept ConvertibleToNotAll = !xieite::concepts::ConvertibleToAll<Source, Targets...>;
```
