# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:ConvertibleToNone
Defined in header [<xieite/concepts/convertible_to_none.hpp>](../../../include/xieite/concepts/convertible_to_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept ConvertibleToNone = !xieite::concepts::ConvertibleToAny<Source, Targets...>;
```
