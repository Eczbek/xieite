# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsNotAll
Defined in header [<xieite/traits/is_same_as_not_all.hpp>](../../../include/xieite/traits/is_same_as_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsSameAsNotAll
: std::bool_constant<xieite::concepts::SameAsNotAll<Source, Targets...>> {};
```
