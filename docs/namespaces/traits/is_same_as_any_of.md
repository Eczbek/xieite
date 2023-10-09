# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsAnyOf
Defined in header [<xieite/traits/is_same_as_any_of.hpp>](../../../include/xieite/traits/is_same_as_any_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsSameAsAnyOf
: std::bool_constant<xieite::concepts::SameAsAnyOf<Source, Targets...>> {};
```
