# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:DerivedFromAll
Defined in header [<xieite/traits/derived_from_all.hpp>](../../../include/xieite/traits/derived_from_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct DerivedFromAll
: std::bool_constant<xieite::concepts::DerivedFromAll<Derived, Bases...>> {};
```
