# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:DerivedFromAny
Defined in header [<xieite/traits/derived_from_any.hpp>](../../../include/xieite/traits/derived_from_any.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct DerivedFromAny
: std::bool_constant<xieite::concepts::DerivedFromAny<Derived, Bases...>> {};
```
