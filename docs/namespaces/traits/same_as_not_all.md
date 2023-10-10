# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:SameAsNotAll
Defined in header [<xieite/traits/same_as_not_all.hpp>](../../../include/xieite/traits/same_as_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct SameAsNotAll
: std::bool_constant<xieite::concepts::SameAsNotAll<Source, Targets...>> {};
```
