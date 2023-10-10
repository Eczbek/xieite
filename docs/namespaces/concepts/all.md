# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:All
Defined in header [<xieite/concepts/all.hpp>](../../../include/xieite/concepts/all.hpp)

&nbsp;

## Description
Specifies that a type satisfies all of several type traits.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept All = (... && requires {
    { Traits<Type>::value } -> std::convertible_to<bool>;
}) && (... && Traits<Type>::value);
```
