# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromAny
Defined in header [<xieite/traits/is_derived_from_any.hpp>](../../../include/xieite/traits/is_derived_from_any.hpp)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromAny
: std::bool_constant<xieite::concepts::DerivedFromAny<Derived, Bases...>> {};
```
