# [xieite](../../xieite.md)\:\:[traits](../../traits.md)\:\:IsNot
Defined in header [<xieite/traits/is_not.hpp>](../../../include/xieite/traits/is_not.hpp)

&nbsp;

## Description
Negates a trait.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, template<typename> typename Trait>
struct IsNot
: std::bool_constant<xieite::concepts::Not<Type, Trait>> {};
```
