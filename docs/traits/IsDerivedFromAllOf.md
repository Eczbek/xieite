# [xieite](../xieite.md)\:\:[traits](../traits.md)\:\:IsDerivedFromAllOf
Defined in header [<xieite/traits/IsDerivedFromAllOf.hpp>](../../include/xieite/traits/IsDerivedFromAllOf.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromAllOf
: std::bool_constant<xieite::concepts::DerivedFromAllOf<Derived, Bases...>> {};
```
