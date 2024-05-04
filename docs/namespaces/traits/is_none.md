# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNone\<\> \{\}
Defined in header [<xieite/traits/is_none.hpp>](../../../include/xieite/traits/is_none.hpp)

&nbsp;

## Description
Negates a trait.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, template<typename> typename Trait_>
struct IsNone
: std::bool_constant<xieite::concepts::None<Type_, Trait_>> {};
```

&nbsp;

## [Example](../concepts/none.md#Example)
