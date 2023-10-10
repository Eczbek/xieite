# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromNotAll
Defined in header [<xieite/traits/is_derived_from_not_all.hpp>](../../../include/xieite/traits/is_derived_from_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromNotAll
: std::bool_constant<xieite::concepts::DerivedFromNotAll<Derived, Bases...>> {};
```
