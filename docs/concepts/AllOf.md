# [xieite](../xieite.md)\:\:[concepts](../concepts.md)\:\:AllOf
Defined in header [<xieite/concepts/AllOf.hpp>](../../include/xieite/concepts/AllOf.hpp)

&nbsp;

## Description
Specifies that a type satisfies all of several type traits.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, xieite::concepts::Trait<Type>... Traits>
concept AllOf = (Traits<Type>::value && ...);
```
