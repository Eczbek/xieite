# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsNone
Defined in header [<xieite/traits/is_same_as_none.hpp>](../../../include/xieite/traits/is_same_as_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsSameAsNone
: std::bool_constant<xieite::concepts::SameAsNone<Source, Targets...>> {};
```
