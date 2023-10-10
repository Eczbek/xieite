# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:SameAsAny
Defined in header [<xieite/traits/same_as_any.hpp>](../../../include/xieite/traits/same_as_any.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct SameAsAny
: std::bool_constant<xieite::concepts::SameAsAny<Source, Targets...>> {};
```
