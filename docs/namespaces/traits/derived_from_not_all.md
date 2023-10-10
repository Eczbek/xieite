# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:DerivedFromNotAll
Defined in header [<xieite/traits/derived_from_not_all.hpp>](../../../include/xieite/traits/derived_from_not_all.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct DerivedFromNotAll
: std::bool_constant<xieite::concepts::DerivedFromNotAll<Derived, Bases...>> {};
```
