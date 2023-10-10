# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleToNotAll
Defined in header [<xieite/concepts/no_throw_convertible_to_not_all.hpp>](../../../include/xieite/concepts/no_throw_convertible_to_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToNotAll = !xieite::concepts::NoThrowConvertibleToAll<Sources, Targets...>;
```
