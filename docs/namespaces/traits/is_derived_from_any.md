# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsDerivedFromAny\<\> \{\}
Defined in fragment [xieite:traits.IsDerivedFromAny](../../../src/traits/is_derived_from_any.cpp)

&nbsp;

## [Description](../concepts/derived_from_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Derived, typename... Bases>
struct IsDerivedFromAny
: std::bool_constant<xieite::concepts::DerivedFromAny<Derived, Bases...>> {};
```

&nbsp;

## [Example](../concepts/derived_from_any.md#Example)
