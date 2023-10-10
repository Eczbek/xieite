# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:SameAsAll
Defined in header [<xieite/traits/same_as_all.hpp>](../../../include/xieite/traits/same_as_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct SameAsAll
: std::bool_constant<xieite::concepts::SameAsAll<Source, Targets...>> {};
```
