# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsSameAsAnyOf
Defined in header [<xieite/traits/IsSameAsAnyOf.hpp>](../../include/xieite/traits/IsSameAsAnyOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsSameAsAnyOf
: std::bool_constant<xieite::concepts::SameAsAnyOf<Source, Targets...>> {};
```
