# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsBaseOf\<\> \{\}
Defined in fragment [xieite:traits.IsBaseOf](../../../src/traits/is_base_of.cpp)

&nbsp;

## [Description](../concepts/base_of.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Base, typename Derived>
struct IsBaseOf
: std::bool_constant<xieite::concepts::BaseOf<Base, Derived>> {};
```

&nbsp;

## [Example](../concepts/base_of.md#Example)
