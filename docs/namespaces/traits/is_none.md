# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNone\<\> \{\}
Defined in fragment [xieite:traits.IsNone](../../../src/traits/is_none.cpp)

&nbsp;

## Description
Negates a trait.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
struct IsNone
: std::bool_constant<xieite::concepts::None<Type, Traits...>> {};
```

&nbsp;

## [Example](../concepts/none.md#Example)
