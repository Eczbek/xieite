# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromAll \{\}
Defined in header [<xieite/traits/is_derived_from_all.hpp>](../../../include/xieite/traits/is_derived_from_all.hpp)

&nbsp;

## [Description](../concepts/derived_from_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromAll
: std::bool_constant<xieite::concepts::DerivedFromAll<Derived, Bases...>> {};
```

&nbsp;

## [Example](../concepts/derived_from_all.md#Example)
