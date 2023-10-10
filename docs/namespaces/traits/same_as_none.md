# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:SameAsNone
Defined in header [<xieite/traits/same_as_none.hpp>](../../../include/xieite/traits/same_as_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct SameAsNone
: std::bool_constant<xieite::concepts::SameAsNone<Source, Targets...>> {};
```
