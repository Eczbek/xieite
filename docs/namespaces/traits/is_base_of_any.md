# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsBaseOfAny\<\> \{\}
Defined in fragment [xieite:traits.IsBaseOfAny](../../../src/traits/is_base_of_any.cpp)

&nbsp;

## [Description](../concepts/base_of_any.md#Description)

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Base, typename... Derived>
struct IsBaseOfAny
: std::bool_constant<xieite::concepts::BaseOfAny<Base, Derived...>> {};
```

&nbsp;

## [Example](../concepts/base_of_any.md#Example)
