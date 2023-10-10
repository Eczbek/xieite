# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:SameAsNotAll
Defined in header [<xieite/concepts/same_as_not_all.hpp>](../../../include/xieite/concepts/same_as_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
concept SameAsNotAll = !xieite::concepts::SameAsAll<Source, Targets...>;
```
