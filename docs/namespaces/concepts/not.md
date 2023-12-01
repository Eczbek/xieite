# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:Not
Defined in header [<xieite/concepts/not.hpp>](../../../include/xieite/concepts/not.hpp)

&nbsp;

## Description
Negates a trait.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename Trait>
concept Not = requires {
    { Trait<Type>::value } -> std::convertible_to<bool>;
} && !Trait<Type>::value;
```
