# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNone \{\}
Defined in header [<xieite/traits/is_none.hpp>](../../../include/xieite/traits/is_none.hpp)

&nbsp;

## Description
Negates a trait.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename Trait>
struct IsNone
: std::bool_constant<xieite::concepts::None<Type, Trait>> {};
```

&nbsp;

## [Example](../concepts/none.md#Example)
