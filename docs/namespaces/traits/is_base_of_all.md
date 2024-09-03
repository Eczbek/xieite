# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsBaseOfAll\<\> \{\}
Defined in fragment [xieite:traits.IsBaseOfAll](../../../src/traits/is_base_of_all.cpp)

&nbsp;

## [Description](../concepts/base_of_all.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Base, typename... Derived>
struct IsBaseOfAll
: std::bool_constant<xieite::concepts::BaseOfAll<Base, Derived...>> {};
```

&nbsp;

## [Example](../concepts/base_of_all.md#Example)
