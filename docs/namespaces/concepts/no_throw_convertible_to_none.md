# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:NoThrowConvertibleToNone
Defined in header [<xieite/concepts/no_throw_convertible_to_none.hpp>](../../../include/xieite/concepts/no_throw_convertible_to_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept NoThrowConvertibleToNone = !xieite::concepts::NoThrowConvertibleToAny<Sources, Targets...>;
```
