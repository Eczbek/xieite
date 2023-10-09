# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsSameAsAllOf
Defined in header [<xieite/traits/is_same_as_all_of.hpp>](../../../include/xieite/traits/is_same_as_all_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Source, typename... Targets>
struct IsSameAsAllOf
: std::bool_constant<xieite::concepts::SameAsAllOf<Source, Targets...>> {};
```
