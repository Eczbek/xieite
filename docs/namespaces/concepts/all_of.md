# [xieite](../../xieite.md)\:\:[concepts](../../concepts.md)\:\:AllOf
Defined in header [<xieite/concepts/all_of.hpp>](../../../include/xieite/concepts/all_of.hpp)

&nbsp;

## Description
Specifies that a type satisfies all of several type traits.

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type, template<typename> typename... Traits>
concept AllOf = (... && requires {
    { Traits<Type>::value } -> std::convertible_to<bool>;
}) && (... && Traits<Type>::value);
```
