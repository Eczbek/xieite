# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromAll\<\> \{\}
Defined in fragment [xieite:traits.IsDerivedFromAll](../../../src/traits/is_derived_from_all.cpp)

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
