# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromAll
Defined in header [<xieite/traits/is_derived_from_all.hpp"](../../../include/xieite/traits/is_derived_from_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromAll
: std::bool_constant<xieite::concepts::DerivedFromAll<Derived, Bases...>> {};
```
