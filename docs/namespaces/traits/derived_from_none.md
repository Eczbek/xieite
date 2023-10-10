# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:DerivedFromNone
Defined in header [<xieite/traits/derived_from_none.hpp>](../../../include/xieite/traits/derived_from_none.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct DerivedFromNone
: std::bool_constant<xieite::concepts::DerivedFromNone<Derived, Bases...>> {};
```
