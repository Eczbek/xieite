# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromNone
Defined in header [<xieite/traits/is_derived_from_none.hpp>](../../../include/xieite/traits/is_derived_from_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromNone
: std::bool_constant<xieite::concepts::DerivedFromNone<Derived, Bases...>> {};
```
