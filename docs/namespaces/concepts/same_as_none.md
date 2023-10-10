# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsNone
Defined in header [<xieite/concepts/same_as_none.hpp>](../../../include/xieite/concepts/same_as_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsNone = !xieite::concepts::SameAsAny<Source, Targets...>;
```
