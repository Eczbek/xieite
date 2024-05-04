# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromAny\<\> \{\}
Defined in header [<xieite/traits/is_derived_from_any.hpp>](../../../include/xieite/traits/is_derived_from_any.hpp)

&nbsp;

## [Description](../concepts/derived_from_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived_, typename... Bases_>
struct IsDerivedFromAny
: std::bool_constant<xieite::concepts::DerivedFromAny<Derived_, Bases_...>> {};
```

&nbsp;

## [Example](../concepts/derived_from_any.md#Example)
