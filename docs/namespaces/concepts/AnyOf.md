# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:AnyOf
Defined in header [<xieite/concepts/AnyOf.hpp>](../../../include/xieite/concepts/AnyOf.hpp)

&nbsp;

## Description
Specifies that a type satisfies at least one of several type traits.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept AnyOf = (... && requires {
    { Traits<Type>::value } -> std::convertible_to<bool>;
}) && (... || Traits<Type>::value);
```
