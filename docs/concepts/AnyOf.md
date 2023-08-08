# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:AnyOf
Defined in header [<xieite/concepts/AnyOf.hpp>](../../include/xieite/concepts/AnyOf.hpp)

&nbsp;

## Description
Specifies that a type satisfies at least one of several type traits.

&nbsp;

## Synopsis
```cpp
template<typename Type, xieite::concepts::Trait<Type>... Traits>
concept AnyOf = (Traits<Type>::value || ...);
```
