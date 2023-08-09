# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsDerivedFromAnyOf
Defined in header [<xieite/traits/IsDerivedFromAnyOf.hpp>](../../include/xieite/traits/IsDerivedFromAnyOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromAnyOf
: std::bool_constant<xieite::concepts::DerivedFromAnyOf<Derived, Bases...>> {};
```
