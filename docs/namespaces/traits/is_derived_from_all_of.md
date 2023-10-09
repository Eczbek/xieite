# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromAllOf
Defined in header [<xieite/traits/is_derived_from_all_of.hpp>](../../../include/xieite/traits/is_derived_from_all_of.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromAllOf
: std::bool_constant<xieite::concepts::DerivedFromAllOf<Derived, Bases...>> {};
```
