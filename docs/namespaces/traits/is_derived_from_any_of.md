# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromAnyOf
Defined in header [<xieite/traits/is_derived_from_any_of.hpp>](../../../include/xieite/traits/is_derived_from_any_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromAnyOf
: std::bool_constant<xieite::concepts::DerivedFromAnyOf<Derived, Bases...>> {};
```
